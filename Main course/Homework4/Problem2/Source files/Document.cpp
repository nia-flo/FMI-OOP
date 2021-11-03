#include "Document.hpp"

#include <sstream>

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
    : Object(name, location, extension)
{
    this->currentLine = this->START_LINE;
}

void Document::write_line(const std::string& line)
{
    this->lines.push_back(line);
}

std::string Document::read_line()
{
    if (this->currentLine < 0 || this->currentLine >= this->lines.size())
    {
        throw std::out_of_range("There isn't any suitable line to be read");
    }

    return this->lines[this->currentLine++];
}

std::string Document::read_line(const unsigned line)
{
    this->currentLine = line - 1;

    return this->read_line();
}

bool Document::operator==(const Comparable* toCompare) const
{
    const Document* toCompareDocument = dynamic_cast<const Document*>(toCompare);

    if (!toCompareDocument)
    {
        return false;
    }

    return (*this == *toCompareDocument);
}

bool Document::operator!=(const Comparable* toCompare) const
{
    return !(*this == toCompare);
}

bool Document::operator==(const Document& toCompare) const
{

    if (this->lines.size() != toCompare.lines.size())
    {
        return false;
    }

    for (int i = 0; i < this->lines.size(); i++)
    {
        if (this->lines[i] != toCompare.lines[i])
        {
            return false;
        }
    }

    return true;
}

bool Document::operator!=(const Document& toCompare) const
{
    return !(*this == toCompare);
}

std::string Document::to_string() const
{
    std::stringstream result;

    result << this->Object::to_string();

    for (int i = 0; i < this->lines.size(); i++)
    {
        result << this->lines[i] << '\n';
    }

    return result.str();
}

void Document::from_string(const std::string& stringData)
{
    std::stringstream data(stringData);

    std::getline(data, this->name);
    std::getline(data, this->location);
    std::getline(data, this->extension);

    this->lines.clear();

    std::string line;
    while (std::getline(data, line))
    {
        this->lines.push_back(line);
    }
}

std::string Document::debug_print() const
{
    std::stringstream result;
    for (int i = 0; i < this->lines.size(); i++)
    {
        result << "Line " << i + 1 << ':' << this->lines[i] << '\n';
    }

    return result.str();
}

Object* Document::clone() const
{
    return new Document(*this);
}
