// ImageMessager.cpp : Defines the entry point for the console application//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include "BitMaps.h"
#include "FileWriter.h"
#include "Validation.h"
#include "FileReader.h"

void DoWrite()
{
	Validation valid;
	bool accurateInput = false;
	int userHeight;
	int userWidth;
	std::string s_userHeight;
	std::string s_userWidth;
	////Get diamensions of image
	do
	{
		std::cout << "Give height of image" << std::endl;
		std::cin >> s_userHeight;
		std::cout << "Give width of image" << std::endl;
		std::cin >> s_userWidth;
		if (!valid.ContaintsLetters(&s_userHeight) || !valid.ContaintsLetters(&s_userWidth))
			std::cout << "Can not contain letters " << std::endl;
		else
		{
			userHeight = std::stoi(s_userHeight);
			userWidth = std::stoi(s_userWidth);
			if (userHeight > 100 || userWidth > 100)
				accurateInput = true;
			else
				std::cout << "Value too small " << std::endl;
		}
	} while (!accurateInput);
	////Get the name and message from user
	const int WIDTH = userWidth;
	const int HEIGHT = userHeight;

	BitManager::Bitmap bitmap(WIDTH, HEIGHT);

	std::string s_Name = "";
	std::string s_Message = "";

	//Get File name
	do
	{
		std::cout << "Give name of file, no digits or spaces." << std::endl;
		std::cin >> s_Name;
	} while (s_Name.length() == 0 || valid.hasNumbers(&s_Name));

	valid.CorrectName(&s_Name);

	//Get message
	std::cout << "Give message for the file." << std::endl;
	std::cin.ignore();
	std::getline(std::cin, s_Message);
	valid.CorrectMessage(&s_Message);

	//Create char array's for writing to bitmap
	char *message = new char[s_Message.length() + 1];
	char *name = new char[s_Name.length() + 1];
	strcpy_s(message, s_Message.size() + 1, s_Message.c_str());
	strcpy_s(name, s_Name.size() + 1, s_Name.c_str());

	////Write the bitmap

	FileWriter filewriter(&bitmap, name);
	if (!filewriter.WriteMap(message, s_Message.size() + 1))
	{
		std::cout << "Something went wrong" << std::endl;
		return;
	}
	std::cout << "Ran Correctly" << std::endl;
}
void DoRead()
{
	
	Validation valid;
	FileReader reader(&valid);
	std::string fileName;
	std::cout << "Please give name of the bitmap " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, fileName);
	valid.hasNumbers(&fileName);
	valid.CorrectName(&fileName);
	std::cout << fileName << std::endl;
	reader.ReadFile(fileName);
	


}
int main()
{

	bool accurateInput = false;
	char input;
	do
	{
		std::cout << "Write or Read image ?" << std::endl;
		std::cout << "Write: 'w' " << std::endl;
		std::cout << "Read: 'r'" << std::endl;
		std::cin >> input;
		switch (input)
		{
		case 'W': accurateInput = true; DoWrite(); break;
		case 'w': accurateInput = true; DoWrite(); break;
		case 'r': accurateInput = true; DoRead();  break;
		case 'R': accurateInput = true; DoRead();  break;
		default: std:cout << "Input is incorrect " << std::endl;
		}
	} while (!accurateInput);



	system("PAUSE");
    return 0;
}

