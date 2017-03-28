/*
 * Ledlib.cpp
 *
 *  Created on: Jan 29, 2017
 *  Author: Pavel Obischenko
 */

#include "Ledlib.h"
#include "Led.h"

#include <Arduino.h>

#define LEDLIB_SLOT_NOT_FOUND -1
#define LEDLIB_LIST_INCREMENT  10

namespace ledlib {
	Ledlib::Ledlib() : ledListCapacity(10), ledList(0) {
		reallocLedList();
	}

	LedlibPtr Ledlib::getInstance() {
		static LedlibPtr instance = 0;
		if (!instance) {
			instance = new Ledlib();
		}
		return instance;
	}

	void Ledlib::addLed(LedPtr led) {
		int freeSlotIndex = findFreeLedSlot();

		if (freeSlotIndex == LEDLIB_SLOT_NOT_FOUND) {
			freeSlotIndex = ledListCapacity;
			ledListCapacity += LEDLIB_LIST_INCREMENT;
			reallocLedList();
		}

		ledList[freeSlotIndex] = led;
	}

	void Ledlib::removeLed(LedPtr led) {
		int ledIndex = findLedIndex(led);
		if (ledIndex != LEDLIB_LIST_INCREMENT) {
			ledList[ledIndex] = 0;
		}
	}

	void Ledlib::reallocLedList() {
		LedPtr* oldList = ledList;

		ledList = new LedPtr[ledListCapacity];
		memset(ledList, 0, ledListCapacity * sizeof(LedPtr));

		if (oldList) {
			memcpy(ledList, oldList, ledListCapacity * sizeof(LedPtr));
			delete [] oldList;
		}
	}

	int Ledlib::findFreeLedSlot() {
		for (int i = 0; i < ledListCapacity; ++i) {
			if (!ledList[i]) {
				return i;
			}
		}
		return LEDLIB_SLOT_NOT_FOUND;
	}

	int Ledlib::findLedIndex(LedPtr led) {
		for (int i = 0; i < ledListCapacity; ++i) {
			if (ledList[i] == led) {
				return i;
			}
		}
		return LEDLIB_SLOT_NOT_FOUND;
	}

	void Ledlib::update() {
		static unsigned long prevTime = 0;

		unsigned long currentTime = millis();
		unsigned int deltaTime = (unsigned int)(currentTime - prevTime);
		prevTime = currentTime;

		Ledlib::update(deltaTime);
	}

	void Ledlib::update(unsigned int dt) {
		LedlibPtr inst = getInstance();

		for (int i = 0; i < inst->ledListCapacity; ++i) {
			LedPtr ledPtr = inst->ledList[i];
			if (ledPtr) {
				ledPtr->update(dt);
			}
		}
	}
} /* namespace ledlib */
