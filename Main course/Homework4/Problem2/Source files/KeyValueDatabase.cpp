#include "KeyValueDatabase.hpp"
#include "HelperFunctions.h"

#include <stdexcept>
#include <sstream>

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension)
{
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	if (this->find(entry.first) != nullptr)
	{
		throw std::invalid_argument("Entry already exists in the key-value database.");
	}

	this->data.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	const std::pair<std::string, int>* entry = this->find(key);

	if (entry == nullptr)
	{
		throw std::invalid_argument("Entry doesn't exist in the key-value database.");
	}

	return entry->second;
}

bool KeyValueDatabase::operator==(const Comparable* toCompare) const
{
	const KeyValueDatabase* toCompareDB = dynamic_cast<const KeyValueDatabase*>(toCompare);

	if (!toCompareDB)
	{
		return false;
	}

	return (*this == *toCompareDB);
}

bool KeyValueDatabase::operator!=(const Comparable* toCompare) const
{
	return !(*this == toCompare);
}

bool KeyValueDatabase::operator==(const KeyValueDatabase& toCompare) const
{
	if (this->data.size() != toCompare.data.size())
	{
		return false;
	}

	for (auto entry : this->data)
	{
		try
		{
			if (toCompare.get_value(entry.first) != entry.second)
			{
				return false;
			}
		}
		catch (std::invalid_argument ex)
		{
			return false;
		}
	}

	return true;
}

bool KeyValueDatabase::operator!=(const KeyValueDatabase& toCompare) const
{
	return !(*this == toCompare);
}

std::string KeyValueDatabase::to_string() const
{
	std::stringstream result;

	result << this->Object::to_string();

	for (auto entry : this->data)
	{
		result << entry.first << ':' << entry.second << '\n';
	}

	return result.str();
}

void KeyValueDatabase::from_string(const std::string& stringData)
{
	std::stringstream data(stringData);

	std::getline(data, this->name);
	std::getline(data, this->location);
	std::getline(data, this->extension);

	this->data.clear();

	std::string line;
	while (std::getline(data, line))
	{
		std::vector<std::string> splittedLine = HelperFunctions::SplitLine(line, ':');
		this->add_entry({ splittedLine[0], HelperFunctions::StringToInt(splittedLine[1]) });
	}
}

std::string KeyValueDatabase::debug_print() const
{
	std::stringstream result;

	for (auto entry : this->data)
	{
		result << '{' << entry.first << ':' << entry.second << "}\n";
	}

	return result.str();
}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}

const std::pair<std::string, int>* KeyValueDatabase::find(const std::string& key) const
{
	for (int i = 0; i < this->data.size(); i++)
	{
		if (this->data[i].first == key)
		{
			return &(this->data[i]);
		}
	}

	return nullptr;
}
