/*
 * ColorConverter.cpp
 *
 *  Created on: Jan 28, 2017
 *  Author: Pavel Obischenko
 */

#include "ColorConverter.h"

namespace ledlib {
	const unsigned int ColorConverter::dim_curve[] = {
		0,   1,   1,   2,   2,   2,   2,   2,   2,   3,   3,   3,   3,   3,   3,   3,
		3,   3,   3,   3,   3,   3,   3,   4,   4,   4,   4,   4,   4,   4,   4,   4,
		4,   4,   4,   5,   5,   5,   5,   5,   5,   5,   5,   5,   5,   6,   6,   6,
		6,   6,   6,   6,   6,   7,   7,   7,   7,   7,   7,   7,   8,   8,   8,   8,
		8,   8,   9,   9,   9,   9,   9,   9,   10,  10,  10,  10,  10,  11,  11,  11,
		11,  11,  12,  12,  12,  12,  12,  13,  13,  13,  13,  14,  14,  14,  14,  15,
		15,  15,  16,  16,  16,  16,  17,  17,  17,  18,  18,  18,  19,  19,  19,  20,
		20,  20,  21,  21,  22,  22,  22,  23,  23,  24,  24,  25,  25,  25,  26,  26,
		27,  27,  28,  28,  29,  29,  30,  30,  31,  32,  32,  33,  33,  34,  35,  35,
		36,  36,  37,  38,  38,  39,  40,  40,  41,  42,  43,  43,  44,  45,  46,  47,
		48,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  62,
		63,  64,  65,  66,  68,  69,  70,  71,  73,  74,  75,  76,  78,  79,  81,  82,
		83,  85,  86,  88,  90,  91,  93,  94,  96,  98,  99,  101, 103, 105, 107, 109,
		110, 112, 114, 116, 118, 121, 123, 125, 127, 129, 132, 134, 136, 139, 141, 144,
		146, 149, 151, 154, 157, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 190,
		193, 196, 200, 203, 207, 211, 214, 218, 222, 226, 230, 234, 238, 242, 248, 255,
	};

	void ColorConverter::convertHSVtoRGB(unsigned int hue, unsigned int sat, unsigned int val, unsigned int &red, unsigned int &green, unsigned int &blue) {
		hue = 360 - (hue % 360);
		red = green = blue = val;

		unsigned int base = ((255UL - sat) * val) >> 8;
		unsigned int hueOver60 = hue / 60;
		unsigned int modHueOver60 = hue % 60;

		if (sat > 0 && val > 0) {
			switch(hueOver60) {
			case 0:
				green = (((val - base) * hue) / 60) + base;
				blue = base;
				break;

			case 1:
				red = (((val - base) * (60 - modHueOver60)) / 60) + base;
				blue = base;
				break;

			case 2:
				red = base;
				blue = (((val - base) * modHueOver60) / 60) + base;
				break;

			case 3:
				red = base;
				green = (((val - base) * (60 - modHueOver60)) / 60) + base;
				break;

			case 4:
				red = (((val - base) * modHueOver60) / 60) + base;
				green = base;
				break;

			case 5:
				green = base;
				blue = (((val - base) * (60 - modHueOver60)) / 60) + base;
				break;
			}
		}
	}

	unsigned int ColorConverter::realBrightness(unsigned int value) {
		value = value > 255 ? 255 : value;
		return dim_curve[value];
	}
}
