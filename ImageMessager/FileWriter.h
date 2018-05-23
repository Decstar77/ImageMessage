#pragma once
#include <fstream>
#include "BitMaps.h"
class FileWriter
{
	private:
		BitManager::Bitmap *map;
		int messageInc;
		const char* name;
		const char* message;

	public:
		bool WriteMap(const char*, int);
		FileWriter(BitManager::Bitmap*, const char*); //Bitmap class, name, message
		~FileWriter();
};

