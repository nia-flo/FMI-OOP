#pragma once

#include "Object.hpp"

#include <vector>

class Document : public Object
{
public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);

    bool operator==(const Comparable* toCompare) const override;
    bool operator!=(const Comparable* toCompare) const override;
    bool operator==(const Document& toCompare) const;
    bool operator!=(const Document& toCompare) const;

    std::string to_string() const override;
    void from_string(const std::string& stringData) override;

    std::string debug_print() const override;

    Object* clone() const override;

private:
    static const int START_LINE = 0;

    std::vector<std::string> lines;
    int currentLine;
};
