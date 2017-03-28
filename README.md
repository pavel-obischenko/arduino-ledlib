# Arduino RGB Led Library

#include "ledlib/Ledlib.h"
using namespace ledlib;

#define LED_RED_PIN         11
#define LED_GREEN_PIN       10
#define LED_BLUE_PIN        9
#define LED_ANIMATION_SPEED 300

// hue: 0 - 360 degrees
#define LED_RED_HUE         0
#define LED_GREEN_HUE       120
#define LED_BLUE_HUE        240

// saturation: 0 - 255
#define LED_SATURATION      255

// brightness: 0 - 255
#define LED_BRIGHTNESS      255

RGBLed led(LED_RED_PIN, LED_GREEN_PIN, LED_BLUE_PIN, kLedModeAnalog, LED_ANIMATION_SPEED);

void setup() {
	led.setHSBColor(LED_RED_HUE, LED_SATURATION, LED_BRIGHTNESS);
}

void loop() {
    // TODO: your code ....
 
    // call update after each loop cycle
    Ledlib::update();
}
