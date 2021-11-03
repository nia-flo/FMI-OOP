#pragma once

#include "Object.hpp"

#include <vector>

class KeyValueDatabase : public Object
{
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    bool operator==(const Comparable* toCompare) const override;
    bool operator!=(const Comparable* toCompare) const override;
    bool operator==(const KeyValueDatabase& toCompare) const;
    bool operator!=(const KeyValueDatabase& toCompare) const;

    std::string to_string() const override;
    void from_string(const std::string& stringData) override;

    std::string debug_print() const override;

    Object* clone() const override;

private:
    std::vector< std::pair<std::string, int> > data;

    const std::pair<std::string, int>* find(const std::string& key) const;
};
