/*
 * Led.h
 *
 *  Created on: Jan 29, 2017
 *  Author: Pavel Obischenko
 */

#ifndef SRC_LEDLIB_LED_H_
#define SRC_LEDLIB_LED_H_

namespace ledlib {
	typedef enum LedMode {
		kLedModeAnalog,
		kLedModeDigital
	};

	class Led {
	public:
		explicit Led(unsigned int ledPin, unsigned int mode, unsigned int animationSpeed = 300);
		virtual ~Led();

		virtual void on(bool animated = true);
		virtual void off(bool animated = true);

		virtual bool isAnimated();

		virtual void setBrightness(unsigned int brightness, bool animated = true);
		unsigned int getBrightness();

		virtual void update(unsigned int dt);

	private:
		unsigned int pin;
		unsigned int mode;

		unsigned int brightness;
		float currentBrightness;

		float animationSpeed;

		bool needUpdatePin;
	};

	typedef Led* LedPtr;
} /* namespace ledlib */

#endif /* SRC_LEDLIB_LED_H_ */
