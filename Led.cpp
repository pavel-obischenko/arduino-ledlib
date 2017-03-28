/*
 * Led.cpp
 *
 *  Created on: Jan 29, 2017
 *  Author: Pavel Obischenko
 */

#include "Led.h"
#include "Ledlib.h"

#include "ColorConverter.h"

#include <Arduino.h>

#define LEDLIB_MAX_BRIGHTNESS 255

namespace ledlib {
	Led::Led(unsigned int ledPin, unsigned int mode, unsigned int animationSpeed/* = 300*/) : pin(ledPin), mode(mode), brightness(0),
			currentBrightness(0), needUpdatePin(true), animationSpeed(animationSpeed * 0.001) {
		Ledlib* ledlib = Ledlib::getInstance();
		ledlib->addLed(this);

		pinMode(pin, OUTPUT);
	}

	Led::~Led() {
		Ledlib* ledlib = Ledlib::getInstance();
		ledlib->removeLed(this);
	}

	void Led::on(bool animated/* = true*/) {
		setBrightness(LEDLIB_MAX_BRIGHTNESS, animated);
	}

	void Led::off(bool animated/* = true*/) {
		setBrightness(0, animated);
	}

	void Led::setBrightness(unsigned int brightness, bool animated/* = true*/) {
		if (mode == kLedModeAnalog) {
			this->brightness = brightness > LEDLIB_MAX_BRIGHTNESS ? LEDLIB_MAX_BRIGHTNESS : brightness;
		}
		else {
			this->brightness = brightness > 0 ? LEDLIB_MAX_BRIGHTNESS : 0;
		}

		currentBrightness = animated && mode == kLedModeAnalog ? currentBrightness : this->brightness;
		needUpdatePin = true;
	}

	unsigned int Led::getBrightness() {
		return brightness;
	}

	bool Led::isAnimated() {
		return mode == kLedModeAnalog && currentBrightness != brightness;
	}

	void Led::update(unsigned int dt) {
		if (currentBrightness != brightness) {
			float dBrightness = dt * animationSpeed;
			needUpdatePin = true;

			if (currentBrightness < brightness) {
				currentBrightness += dBrightness;
				currentBrightness = currentBrightness > brightness ? brightness : currentBrightness;
			}
			else {
				currentBrightness = abs(currentBrightness - brightness) > dBrightness ? currentBrightness - dBrightness : brightness;
			}
		}

		if (needUpdatePin) {
			if (mode == kLedModeAnalog) {
				analogWrite(pin, ColorConverter::realBrightness((unsigned int)(currentBrightness)));
			}
			else {
				digitalWrite(pin, currentBrightness > 0);
			}
			needUpdatePin = false;
		}
	}
} /* namespace ledlib */
