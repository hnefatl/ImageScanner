#include <iostream>
#include <vector>

#include "Image.h"
#include "Pixel.h"

Image::Image()
{

}
Image::Image(std::vector<unsigned char> Data, unsigned long Width, unsigned long Height)
{
	m_Width=Width;
	m_Height=Height;

	m_Pixels.resize(m_Width);
	for(unsigned long x=0; x<m_Pixels.size(); x++)
	{
		m_Pixels[x].resize(m_Height);
	}

	unsigned long Traversed=0;
	for(unsigned long x=0; x<m_Width; x++)
	{
		for(unsigned long y=0; y<m_Height; y++)
		{
			m_Pixels[x][y].m_R=Data[Traversed];
			m_Pixels[x][y].m_G=Data[Traversed+1];
			m_Pixels[x][y].m_B=Data[Traversed+2];
			m_Pixels[x][y].m_A=Data[Traversed+3];
			Traversed++;
		}
	}
}

Pixel Image::GetPixel(int x, int y)
{
	return m_Pixels[x][y];
}