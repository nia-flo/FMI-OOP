#pragma once

#include <vector>
#include <string>

class HelperFunctions
{
public:
	virtual ~HelperFunctions() = 0;

	static std::vector<std::string> SplitLine(const std::string& line, char separator);

	static int StringToInt(const std::string& number);
};
