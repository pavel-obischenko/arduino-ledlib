/*
 * ColorConverter.h
 *
 *  Created on: Jan 28, 2017
 *  Author: Pavel Obischenko
 */

#ifndef SRC_LEDLIB_COLORCONVERTER_H_
#define SRC_LEDLIB_COLORCONVERTER_H_

namespace ledlib {
	class ColorConverter {
	private:
		static const unsigned int dim_curve[];

	public:
		static void convertHSVtoRGB(unsigned int hue, unsigned int sat, unsigned int val, unsigned int &red, unsigned int &green, unsigned int &blue);
		static unsigned int realBrightness(unsigned int value);
	};
}

#endif /* SRC_LEDLIB_COLORCONVERTER_H_ */
