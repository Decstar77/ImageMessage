#include "stdafx.h"
#include "FileWriter.h"
#include <iostream>
#include <algorithm>

using namespace BitManager;

FileWriter::FileWriter(Bitmap *m_map,  const char* name)
{
	this->map = m_map;
	this->name = name;
	int messageInc = 0;
}

bool FileWriter::WriteMap(const char* message, int size)
{
	const int sizeMessage = size;
	const int HEIGHT = map->GetHeight();
	const int WIDTH = map->GetWidth();
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (messageInc <= sizeMessage)
			{
				map->setPixel(x, y, message[messageInc++], message[messageInc++], message[messageInc++]);
				
			}
			else
			{
				map->setPixel(x, y, 255, 255, 255);
			}
		}
	}
	return this->map->write(this->name);
}

FileWriter::~FileWriter()
{

}
