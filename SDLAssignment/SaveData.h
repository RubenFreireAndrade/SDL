#pragma once
#include <assert.h>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Screen.h"

class SaveData
{
public:
	SaveData();
	~SaveData();

	void Initialise();
	void ParseString(std::string& srcString, std::vector<std::string>& subStrings, char token);

private:
	Screen m_screen;

	std::string line;
	std::vector<std::string> subStrings;
	std::map<std::string, std::string> dataMap;
	std::fstream file;
};

