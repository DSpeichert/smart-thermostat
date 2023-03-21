#include "thermostat.hpp"  // For function definitions

void setup(void)
{
  // Start serial debugger
  serialStart();
  // Start wifi
  wifiStart();
  // Start web server
  webInit();
  // Initialize indicators (relays, LEDs, buzzer)
  indicatorsInit();
  // Initialize sensors (temp, humidity, motion ... air quality)
  sensorsInit();
  // Play the startup sound
  audioStartupBeep();
  // Initialize the TFT display
  tftInit();
  // Show the splash screen
  displaySplash();
  // Do a quick test of the relays
  testToggleRelays();
  // Create the RTOS task to drive the touchscreen
  tftCreateTask();
  // Create the RTOS task to drive the state machine
  stateCreateTask();
}

void loop(void)
{
  // Nothing to do here since everything is done via RTOS tasks & interrupts
}