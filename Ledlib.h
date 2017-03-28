/*
 * Ledlib.h
 *
 *  Created on: Jan 29, 2017
 *  Author: Pavel Obischenko
 */

#ifndef SRC_LEDLIB_LEDLIB_H_
#define SRC_LEDLIB_LEDLIB_H_

#include "Led.h"
#include "RGBLed.h"

namespace ledlib {
	class Ledlib;
	typedef Ledlib* LedlibPtr;

	class Ledlib {
		friend class Led;

	private:
		Ledlib();

	private:
		static LedlibPtr getInstance();

	private:
		void addLed(LedPtr led);
		void removeLed(LedPtr led);

		void reallocLedList();
		int findFreeLedSlot();
		int findLedIndex(LedPtr led);

	public:
		static void update();
		static void update(unsigned int dt);

	private:
		int ledListCapacity;
		LedPtr* ledList;
	};
} /* namespace ledlib */

#endif /* SRC_LEDLIB_LEDLIB_H_ */
