#ifndef _PIXEL_H
#define _PIXEL_H

#include <iostream>
#include <vector>

class Pixel
{
public:
	Pixel();
	Pixel(unsigned char R, unsigned char G, unsigned char B, unsigned char A);

	unsigned char m_R, m_G, m_B, m_A;
};

#endif