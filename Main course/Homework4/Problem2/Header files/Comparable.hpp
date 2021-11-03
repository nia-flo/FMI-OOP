#pragma once

class Comparable 
{
public:
	virtual bool operator==(const Comparable* toCompare) const = 0;
	virtual bool operator!=(const Comparable* toCompare) const = 0;

	virtual ~Comparable() = default;
};