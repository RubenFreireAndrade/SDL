#include "Parser.h"

void Parser::ParseString(std::string& srcString, std::vector<std::string>& subStrings, char token)
{
	assert(!srcString.empty());

	auto start = 0U;
	auto end = 0U;
	while (end != std::string::npos)
	{
		end = srcString.find(token, start);
		if ((end - start) > 0)
		{
			subStrings.push_back(srcString.substr(start, (end - start)));
		}
		start = end + 1;
	}
}

bool Parser::LoadConfigFile(const std::string& filename, std::map<std::string, std::string>& dataMap)
{
	std::fstream file(filename, std::ios_base::in);
	if (!file.is_open())
	{
		return false;
	}

	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		std::vector<std::string> subStrings;
		ParseString(line, subStrings, '=');

		if (!subStrings.empty())
		{
			dataMap[subStrings[0]] = subStrings[1];
		}
	}
	file.close();
	return true;
}
