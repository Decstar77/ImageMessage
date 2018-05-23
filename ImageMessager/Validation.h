#pragma once
#include "BitMaps.h"
#include <algorithm>
#include <cctype>
class Validation
{
	private:
		int stopKey = static_cast<int>('$');
		int startKey = static_cast<int>('#');

	public:
		void CorrectMessage(std::string*);
		int GetStopKey();
		int GetStartKey();
		bool CorrectName(std::string*);
		bool hasNumbers(std::string*);
		bool ContaintsLetters(std::string*);
		Validation();
		~Validation();
};

