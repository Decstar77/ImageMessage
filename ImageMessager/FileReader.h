#pragma once
#include "BitMaps.h"
#include "Validation.h"
#include <fstream>
#include <vector>
#include <iostream>
class FileReader
{
	private:
		std::string findData(std::vector<char>);
		fstream inFile;
		fstream::pos_type pos;
		Validation *isValid;
	public:
		bool ReadFile(std::string);
		FileReader(Validation*);
		~FileReader();
};

