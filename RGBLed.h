/*
 * RGBLed.h
 *
 *  Created on: Jan 30, 2017
 *  Author: Pavel Obischenko
 */

#ifndef SRC_LEDLIB_RGBLED_H_
#define SRC_LEDLIB_RGBLED_H_

#include "Led.h"

namespace ledlib {
	class RGBLed: public Led {
	public:
		RGBLed(unsigned int redPin, unsigned int greenPin, unsigned int bluePin, unsigned int mode = kLedModeAnalog,
				unsigned int animationSpeed = 300);
		void setHSBColor(unsigned int hue, int saturation, unsigned int brightness);

		void setHue(unsigned int hue, bool animated = true);
		unsigned int getHue();

		void setSaturation(unsigned int saturation, bool animated = true);
		unsigned int getSaturation();

		virtual void setBrightness(unsigned int brightness, bool animated = true);
		unsigned int getBrightness();

		virtual bool isAnimated();

		virtual void update(unsigned int dt);
		void updateColor(bool animated = true);

	private:
		Led redLed;
		Led greenLed;
		Led blueLed;

		unsigned int hue;
		unsigned int saturation;
		unsigned int brightness;
	};
} /* namespace ledlib */

#endif /* SRC_LEDLIB_RGBLED_H_ */
