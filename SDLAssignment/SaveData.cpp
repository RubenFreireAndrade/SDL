#include "SaveData.h"

SaveData::SaveData()
{
	//file("SaveData/Config.ini", std::ios_base::in);
}

SaveData::~SaveData()
{
}

void SaveData::Initialise()
{
	if (!file)
	{
		std::cout << "Error loading file" << std::endl;
	}

	assert(file);

	while (!file.eof())
	{
		std::getline(file, line);
		ParseString(line, subStrings, '=');

		dataMap[subStrings[0]] = subStrings[1];
		subStrings.clear();
	}
}

void SaveData::ParseString(std::string& srcString, std::vector<std::string>& subStrings, char token)
{
	assert(!srcString.empty());

	auto start = 0U;
	auto end = 0U;
	while (end != std::string::npos)
	{
		end = srcString.find(token, start);
		if ((end - start) > 0);
		{
			subStrings.push_back(srcString.substr(start, (end - start)));
		}
		start = end + 1;
	}
}
