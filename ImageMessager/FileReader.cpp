#include "stdafx.h"
#include "FileReader.h"



FileReader::FileReader(Validation *valid)
{
	this->isValid = valid;
}

std::string FileReader::findData(std::vector<char> m_res)
{
	std::string outMessage = "";
	bool out = false;
	int stopkey = this->isValid->GetStopKey();
	int startkey = this->isValid->GetStartKey();
	for (int i = 0; i < m_res.size(); i++)
	{		
		if (m_res.at(i) == static_cast<char>(startkey))
		{
			out = true;
			continue;
		}
		if (out)
		{
			if (m_res.at(i) == static_cast<char>(stopkey))
				break;

			outMessage.push_back(m_res.at(i));
		}
		
	}
	return outMessage;
}

bool FileReader::ReadFile(std::string fileName)
{
	inFile.open(fileName, std::ios::in | std::ios::binary | std::ios::ate);
	if (!inFile)
	{
		std::cout << "Not found" << std::endl;
		return false;
	}
	this->pos = inFile.tellp();
	std::vector<char> res(pos); ////Make it private class
	inFile.seekp(0, ios::beg);
	inFile.read(&res[0], pos);
	inFile.close();
	std::cout << findData(res) << std::endl;
	return true;


}


FileReader::~FileReader()
{
}
