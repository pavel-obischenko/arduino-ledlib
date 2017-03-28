# Arduino RGB Led Library

### Include the library

```c++
#include "arduino-ledlib/Ledlib.h"
using namespace ledlib;
```

### Define needed constants

```c++
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
```

### Declaire and construct the RGBLed object

```c++
RGBLed led(LED_RED_PIN, LED_GREEN_PIN, LED_BLUE_PIN, kLedModeAnalog, LED_ANIMATION_SPEED);
```

### Initialise the led object with hue, saturation and brightness

```c++
void setup() {
    led.setHSBColor(LED_RED_HUE, LED_SATURATION, LED_BRIGHTNESS);
}
```
### To smooth animation don't forget to call Ledlib::update() after each loop cycle or after any delays in your code

```c++
void loop() {
    // TODO: your code ....
 
    // call update after each loop cycle
    Ledlib::update();
}
```
