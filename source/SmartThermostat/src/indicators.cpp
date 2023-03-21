#include "thermostat.hpp"
#include <Adafruit_AHTX0.h>     // For OUTPUT def, pinMode(), ledcXxx() and delay() calls

int freq = 4000;
int channel = 0;
int resolution = 8;

void audioBuzzerInit()
{
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(BUZZER_PIN, channel);
}  

void audioStartupBeep()
{
  ledcWriteTone(channel, 4000);
  ledcWrite(channel, 125);
  delay(125);
  ledcWriteTone(channel, 3000);
  delay(150);
  ledcWriteTone(channel, 0);
}

void audioBeep()
{
  ledcWriteTone(channel, 4000);
  ledcWrite(channel, 125);
  delay(125);
  ledcWriteTone(channel, 0);
}


void indicatorsInit()
{
  pinMode(LED_BUILTIN, OUTPUT);

  // pinMode(LED_HEAT_PIN, OUTPUT);
  // pinMode(LED_COOL_PIN, OUTPUT);
  // pinMode(LED_IDLE_PIN, OUTPUT);

  // digitalWrite(LED_HEAT_PIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_HEAT_PIN, LOW);
  // digitalWrite(LED_COOL_PIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_COOL_PIN, LOW);
  // digitalWrite(LED_IDLE_PIN, HIGH);
  // delay(1000);
  // digitalWrite(LED_IDLE_PIN, LOW);

  audioBuzzerInit();
}