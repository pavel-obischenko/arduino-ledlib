/*
 * RGBLed.cpp
 *
 *  Created on: Jan 30, 2017
 *  Author: Pavel Obischenko
 */

#include "RGBLed.h"
#include "ColorConverter.h"

namespace ledlib {
	RGBLed::RGBLed(unsigned int redPin, unsigned int greenPin, unsigned int bluePin, unsigned int mode,
			unsigned int animationSpeed) : Led(-1, mode, animationSpeed), redLed(redPin, mode, animationSpeed), greenLed(greenPin, mode, animationSpeed),
			blueLed(bluePin, mode, animationSpeed), hue(0), saturation(255), brightness(255) {
	}

	bool RGBLed::isAnimated() {
		return redLed.isAnimated();
	}

	void RGBLed::setBrightness(unsigned int brightness, bool animated = true) {
		this->brightness = brightness;
		updateColor(animated);
	}

	unsigned int RGBLed::getBrightness() {
		return brightness;
	}

	void RGBLed::setHSBColor(unsigned int hue, int saturation, unsigned int brightness) {
		this->hue = hue; this->saturation = saturation; this->brightness = brightness;
		updateColor(false);
	}

	void RGBLed::setHue(unsigned int hue, bool animated = true) {
		this->hue = hue;
		updateColor(animated);
	}

	unsigned int RGBLed::getHue() {
		return hue;
	}

	void RGBLed::setSaturation(unsigned int saturation, bool animated = true) {
		this->saturation = saturation;
		updateColor(animated);
	}

	unsigned int RGBLed::getSaturation() {
		return saturation;
	}

	void RGBLed::update(unsigned int dt) {
	}

	void RGBLed::updateColor(bool animated) {
		unsigned int red, green, blue;
		ColorConverter::convertHSVtoRGB(hue, saturation, brightness, red, green, blue);

		redLed.setBrightness(red, animated);
		greenLed.setBrightness(green, animated);
		blueLed.setBrightness(blue, animated);
	}
} /* namespace ledlib */
