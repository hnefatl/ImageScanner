#include <iostream>
#include <vector>

#include "Pixel.h"

Pixel::Pixel()
{

}
Pixel::Pixel(unsigned char R, unsigned char G, unsigned char B, unsigned char A)
{
	m_R=R;
	m_G=G;
	m_B=B;
	m_A=A;
}