#pragma once
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>

class Parser
{
public:

	void ParseString(std::string& srcString, std::vector<std::string>& subStrings, char token);
	bool LoadConfigFile(const std::string& filename, std::map<std::string, std::string>& dataMap);
private:

	std::string line;
	std::vector<std::string> subStrings;
	std::map<std::string, std::string> dataMap;
};

