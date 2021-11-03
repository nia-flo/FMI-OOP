#include "HelperFunctions.h"

std::vector<std::string> HelperFunctions::SplitLine(const std::string& line, char separator)
{
	std::vector<std::string> result;

	std::string current;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == separator) {
			result.push_back(current);
			current = "";

			continue;
		}

		current += line[i];
	}
	result.push_back(current);

	return result;
}

int HelperFunctions::StringToInt(const std::string& number)
{
	int result = 0;

	for (int i = 0; i < number.size(); i++)
	{
		result *= 10;
		result += number[i] - '0';
	}

	return result;
}