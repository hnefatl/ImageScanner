#ifndef _IMAGE_H
#define _IMAGE_H

#include <iostream>
#include <vector>

#include "Pixel.h"

class Image
{
public:
	Image();
	Image(std::vector<unsigned char> Data, unsigned long Width, unsigned long Height);

	Pixel GetPixel(int x, int y);

private:
	std::vector<std::vector<Pixel>> m_Pixels;
	unsigned long m_Width, m_Height;
};

#endif