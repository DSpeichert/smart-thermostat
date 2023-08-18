/*!
// SPDX-License-Identifier: GPL-3.0-only
/*
 * state_machine.cpp
 *
 * Implements the state machine to control the HVAC actions and modes.
 * As part of this responsibility, statuses of items such as wifi connection
 * are also monitored and action taken if necessary.
 *
 * Copyright (c) 2023 Steve Meisner (steve@meisners.net)
 * 
 * Notes:
 *
 * History
 *  17-Aug-2023: Steve Meisner (steve@meisners.net) - Initial version
 * 
 */

#include "thermostat.hpp"

OPERATING_PARAMETERS OperatingParameters;
extern int32_t lastTimeUpdate;
int32_t lastWifiReconnect = 0;

void stateMachine(void * parameter)
{
  float currentTemp;
  float minTemp, maxTemp;
  float autoMinTemp, autoMaxTemp;

  for(;;) // infinite loop
  {
    OperatingParameters.lightDetected = analogRead(LIGHT_SENS_PIN);

    currentTemp = OperatingParameters.tempCurrent + OperatingParameters.tempCorrection;
    minTemp = OperatingParameters.tempSet - (OperatingParameters.tempSwing / 2.0);
    maxTemp = OperatingParameters.tempSet + (OperatingParameters.tempSwing / 2.0);

#if 0
    autoMinTemp = OperatingParameters.tempSetAutoMin - (OperatingParameters.tempSwing / 2.0);
    autoMaxTemp = OperatingParameters.tempSetAutoMax + (OperatingParameters.tempSwing / 2.0);
#else
    autoMinTemp = minTemp;
    autoMaxTemp = maxTemp;
#endif

    if (OperatingParameters.hvacSetMode == OFF)
    {
      OperatingParameters.hvacOpMode = OFF;
      digitalWrite(HVAC_HEAT_PIN, LOW);
      digitalWrite(HVAC_COOL_PIN, LOW);
      digitalWrite(HVAC_FAN_PIN, LOW);
      digitalWrite(LED_COOL_PIN, LOW);
      digitalWrite(LED_HEAT_PIN, LOW);
      digitalWrite(LED_FAN_PIN, LOW);
    }
    else if (OperatingParameters.hvacSetMode == FAN)
    {
      OperatingParameters.hvacOpMode = FAN;
      digitalWrite(HVAC_HEAT_PIN, LOW);
      digitalWrite(HVAC_COOL_PIN, LOW);
      digitalWrite(HVAC_FAN_PIN, HIGH);
      digitalWrite(LED_COOL_PIN, LOW);
      digitalWrite(LED_HEAT_PIN, LOW);
      digitalWrite(LED_FAN_PIN, HIGH);
    }
    else if (OperatingParameters.hvacSetMode == HEAT)
    {
      if (OperatingParameters.hvacOpMode == COOL)
      {
        digitalWrite(HVAC_COOL_PIN, LOW);
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      if (currentTemp < minTemp)
      {
        OperatingParameters.hvacOpMode = HEAT;
        digitalWrite(HVAC_HEAT_PIN, HIGH);
        digitalWrite(LED_HEAT_PIN, HIGH);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      else
      {
        OperatingParameters.hvacOpMode = IDLE;
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
    }
    else if (OperatingParameters.hvacSetMode == AUX_HEAT)
    {
      //
      // Set up for 2-stage, emergency or aux heat mode
      // Set relays correct
      // For now, just emulate HEAT mode
      //
      if (OperatingParameters.hvacOpMode == COOL)
      {
        //digitalWrite(HVAC_COOL_PIN, LOW);
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      if (currentTemp < minTemp)
      {
        OperatingParameters.hvacOpMode = HEAT;
        digitalWrite(HVAC_HEAT_PIN, HIGH);
        digitalWrite(LED_HEAT_PIN, HIGH);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      else
      {
        OperatingParameters.hvacOpMode = IDLE;
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
    }
    else if (OperatingParameters.hvacSetMode == COOL)
    {
      if (OperatingParameters.hvacOpMode == HEAT)
      {
        digitalWrite(HVAC_HEAT_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      if (currentTemp > maxTemp)
      {
        OperatingParameters.hvacOpMode = COOL;
        digitalWrite(HVAC_COOL_PIN, HIGH);
        digitalWrite(LED_COOL_PIN, HIGH);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      else
      {
        OperatingParameters.hvacOpMode = IDLE;
        digitalWrite(LED_FAN_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_COOL_PIN, LOW);
      }
    }
    else if (OperatingParameters.hvacSetMode == AUTO)
    {
      if (currentTemp < autoMinTemp)
      {
        OperatingParameters.hvacOpMode = HEAT;
        digitalWrite(HVAC_HEAT_PIN, HIGH);
        digitalWrite(LED_HEAT_PIN, HIGH);
        digitalWrite(HVAC_COOL_PIN, LOW);
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      else if (currentTemp > autoMaxTemp)
      {
        OperatingParameters.hvacOpMode = COOL;
        digitalWrite(HVAC_COOL_PIN, HIGH);
        digitalWrite(LED_COOL_PIN, HIGH);
        digitalWrite(HVAC_HEAT_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
      else
      {
        OperatingParameters.hvacOpMode = IDLE;
        digitalWrite(HVAC_COOL_PIN, LOW);
        digitalWrite(HVAC_HEAT_PIN, LOW);
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
      }
    }

    if ((currentTemp >= minTemp) && (currentTemp <= maxTemp) && (OperatingParameters.hvacSetMode != FAN) && (OperatingParameters.hvacSetMode != OFF))
    {
        OperatingParameters.hvacOpMode = IDLE;
        digitalWrite(HVAC_HEAT_PIN, LOW);
        digitalWrite(HVAC_COOL_PIN, LOW);
        digitalWrite(LED_COOL_PIN, LOW);
        digitalWrite(LED_HEAT_PIN, LOW);
        digitalWrite(LED_FAN_PIN, LOW);
    }

    ld2410_loop();
    
    if (millis() - lastTimeUpdate > UPDATE_TIME_INTERVAL)
    {
      lastTimeUpdate = millis();
      updateTimeSntp();
    }

    OperatingParameters.wifiConnected = wifiConnected();

    // Check wifi
    if ((!OperatingParameters.wifiConnected) && (strlen(WifiCreds.ssid)))
    {
      if (millis() > lastWifiReconnect + 60000)
      {
        lastWifiReconnect = millis();
        startReconnectTask();
      }
    }

    if (Serial.available())
    {
      String temp = Serial.readString();
      Serial.print ("[USB] "); Serial.println(temp);
      if (temp.indexOf("reset") > -1)
        ESP.restart();
      // if (temp.indexOf("scan") > -1)
      //   scanI2cBus();
      if (temp.indexOf("temp") > -1)
      {
        Serial.printf ("Current Set Temp: %.1f\n", OperatingParameters.tempSet);
      }
    }

    // Pause the task again for 40ms
    vTaskDelay(40 / portTICK_PERIOD_MS);
  }
}

void stateCreateTask()
{
  xTaskCreate (
    stateMachine,
    "State Machine",
    4096,
    NULL,
    tskIDLE_PRIORITY - 1,
    NULL
  );
}

void testToggleRelays()
{
  delay(500);
  pinMode(HVAC_HEAT_PIN, OUTPUT);
  //@@@ digitalWrite(HVAC_HEAT_PIN, HIGH);
  // delay(750);
  // digitalWrite(HVAC_HEAT_PIN, LOW);
}

void serialStart()
{
  //
  // Serial port mapping:
  //
  // Serial relates to the onboard UART port
  // Serial1 is mapped (I believe) to the SWD port
  // Serial2 is the USB port directly connected to the ESP32
  //  NB: Serial2 is remapped to provide serial comms with the LD2410
  //
  // Do not use Serial2 as this will disable firmware uploading 
  // and debugging via the USB port. It will also cause the USB
  // interface to not show up as a USB device to the host.
  //

  int32_t tmo = millis() + 60000;
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.printf("UART Serial port (via UART-USB adapter -> usually /dev/ttyUSB0)\n");

  // Serial1.begin(115200);
  // Serial1.setDebugOutput(true);
  // Serial1.printf("SERIAL1\n");
}