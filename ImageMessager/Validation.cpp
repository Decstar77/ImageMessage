#include "stdafx.h"
#include "Validation.h"


Validation::Validation()
{
}
int Validation::GetStopKey()
{
	return stopKey;
}
int Validation::GetStartKey()
{
	return startKey;
}
void Validation::CorrectMessage(std::string *s_Message)
{
	s_Message->insert(s_Message->begin(), static_cast<char>(startKey));
	s_Message->push_back(static_cast<char>(stopKey));
}

bool Validation::ContaintsLetters(std::string *s_Name)
{
	if (std::find_if(s_Name->begin(), s_Name->end(), [](char c) { return !std::isalpha(c); }) != s_Name->end())
		return true;
	return false;
}

bool Validation::hasNumbers(string *s_Name)
{
	return std::any_of(s_Name->begin(), s_Name->end(), ::isdigit);
}
bool Validation::CorrectName(string *s_Name)
{
	string isValid = "";
	for (int i = s_Name->length() - 1; i > s_Name->length() - 5; i--)
	{
		isValid.push_back(s_Name->at(i));
	}
	if (strcmp(isValid.c_str(), "pmb."))
	{
		s_Name->append(".bmp");
		return true;
	}
	return false;
}

Validation::~Validation()
{
}
