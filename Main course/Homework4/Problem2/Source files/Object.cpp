#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension)
	: name(name), location(location), extension(extension)
{
}

std::string Object::get_name() const
{
	return this->name;
}

std::string Object::get_location() const
{
	return this->location;
}

std::string Object::get_extension() const
{
	return this->extension;
}

std::string Object::get_fullpath() const
{
	return this->location + '/' + this->name + '.' + this->extension;
}

std::string Object::to_string() const
{
	return this->name + '\n' + this->location + '\n' + this->extension + '\n';
}
