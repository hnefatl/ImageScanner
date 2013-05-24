#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>

#include "PNG.h"
#include "Pixel.h"
#include "Image.h"

bool LoadFile(std::string Path, std::vector<unsigned char> &Data, unsigned long &FileLength);
std::vector<std::vector<float>> GetAverages(std::vector<unsigned char> Data, unsigned long Width, unsigned long Height,
	unsigned int ChunkWidth, unsigned int ChunkHeight);


int main(int argc, char *argv[])
{
	std::string Path;
	std::cout<<"Enter path to file: ";
	std::getline(std::cin, Path);

	std::vector<unsigned char> Data;
	unsigned long FileLength;

	if(!LoadFile(Path, Data, FileLength))
	{
		std::cout<<"File could not be found."<<std::endl;
		_getch();
		return 1;
	}

	unsigned int Width, Height;
	lodepng::decode(Data, Width, Height, Data.size()>0?&Data[0]:0, (unsigned long)Data.size());

	Image Img(Data, Width, Height);

	Pixel p=Img.GetPixel(1, 0);

	std::cout<<p.m_R<<p.m_G<<p.m_B<<p.m_A;

	_getch();
	return 0;
}

bool LoadFile(std::string Path, std::vector<unsigned char> &Data, unsigned long &FileLength)
{
	std::fstream File(Path, std::ios::ate|std::ios::in|std::ios::binary);
	if(!File.good())
	{
		return false;
	}

	File.seekg(0, std::ios::end);
	FileLength = (unsigned long)File.tellg();

	Data.resize(FileLength);
	File.read((char *)(&Data[0]), FileLength);

	return true;
}
std::vector<std::vector<float>> GetAverages(std::vector<unsigned char> Data, unsigned long Width, unsigned long Height,
	unsigned int ChunkWidth, unsigned int ChunkHeight)
{
	// Create and map out averages array
	std::vector<std::vector<float>> Averages;
	unsigned int AvgWidth, AvgHeight;
	AvgWidth=(Width%ChunkWidth>0) ? (Width/ChunkWidth+1) : (Width/ChunkWidth);
	AvgHeight=(Height%ChunkHeight>0) ? (Height/ChunkHeight+1) : (Height/ChunkHeight);

	Averages.resize(AvgWidth);
	for(unsigned int x=0; x<Averages.size(); x++)
	{
		Averages[x].resize(AvgHeight);
	}

	for(unsigned int x=0; x<Averages.size(); x++)
	{
		for(unsigned int y=0; y<Averages[x].size(); y++)
		{
			double Avg;
			for(unsigned int a=0; a<ChunkWidth; a++)
			{
				for(unsigned int b=0; b<ChunkHeight; b++)
				{

				}
			}

		}
	}

	return Averages;
}