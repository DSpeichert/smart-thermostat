// SPDX-License-Identifier: GPL-3.0-only
/*
 * main.cpp
 *
 * Primary entry point for starting the thermostat firmware. This module
 * calls all of the start/initialization functions of the thermostat. 
 * A side effect of initialiing the module is all RTOS tasks are started.
 *
 * Copyright (c) 2023 Steve Meisner (steve@meisners.net)
 * 
 * Notes:
 *
 * History
 *  17-Aug-2023: Steve Meisner (steve@meisners.net) - Initial version
 *  30-Aug-2023: Steve Meisner (steve@meisners.net) - Rewrote to support ESP-IDF framework instead of Arduino
 * 
 */

#include "thermostat.hpp"

#include "esp_timer.h"
int32_t millis() { return esp_timer_get_time() / 1000;}

void app_main()
{
  // Load configuration from EEPROM
  printf ("Reading EEPROM\n");
  eepromInit();

  // Initialize the TFT display
  printf ("Initializing TFT\n");
  tftInit();
  // Create the RTOS task to drive the touchscreen
  printf ("Starting TFT task\n");
  tftCreateTask();

  // Start wifi
  printf ("Starting wifi (\"%s\", \"%s\")\n", WifiCreds.ssid, WifiCreds.password);
  OperatingParameters.wifiConnected = 
    wifiStart(WifiCreds.hostname, WifiCreds.ssid, WifiCreds.password);

  // Initialize indicators (relays, LEDs, buzzer)
  printf ("Initializing indicators\n");
  indicatorsInit();
  // Initialize sensors (temp, humidity, motion, etc)
  printf ("Initializing sensors\n");
  sensorsInit();

  // Create the RTOS task to drive the state machine
  printf ("Starting state machine task\n");
  stateCreateTask();

  // Start web server
  // printf ("Starting web server\n");
  webStart();

  // Play the startup sound
  audioStartupBeep();
  printf ("Startup done\n");
}