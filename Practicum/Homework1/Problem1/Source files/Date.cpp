/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefania Tsvetkova
* @idnumber 62573
* @task 1
* @compiler VC
*/

#include "Date.hpp"

//public functions

Date::Date() //Default Constructor
	: day(1), month(1), year(2000)
{
}

Date::Date(int day, int month, int year) //Constructor
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& date) //Copy Constructor
{
	this->Copy(date);
}

Date& Date::operator=(const Date& date)
{
	this->Copy(date);

	return *this;
}

Date::~Date() {} //Destructor

//Accessors

int Date::GetDay()
{
	return this->day;
}

int Date::GetMonth()
{
	return this->month;
}

int Date::GetYear()
{
	return this->year;
}

//Operations

void Date::AddDays(int daysCount)
{
	this->day += daysCount;

	while (this->day > this->MonthLenght())
	{
		this->day -= this->MonthLenght();

		this->month++;
		if (this->month == 13)
		{
			this->month = 1;
			this->year++;
		}
	}
}

void Date::RemoveDays(int daysCount)
{
	this->day -= daysCount;

	while (this->day < 1) {
		this->month--;
		if (this->month == 0)
		{
			this->month = 12;
			this->year--;
		}

		this->day += MonthLenght();
	}
}

bool Date::IsLeapYear()
{
	return (this->year % 4 == 0 && (this->year % 100 != 0 || this->year % 400 == 0));
}

int Date::DaysTo(const Date& date)
{
	if (date.day == this->day && date.month == this->month && date.year == this->year)
	{
		return 0;
	}

	Date thisCopy(*this);
	int daysCount = 0;

	while (thisCopy.year < date.year)
	{
		if (thisCopy.IsLeapYear())
		{
			daysCount += 366;
			thisCopy.AddDays(366);
		}
		else
		{
			daysCount += 365;
			thisCopy.AddDays(365);
		}
	}

	while (thisCopy.month < date.month)
	{
		int addedDays = thisCopy.MonthLenght();
		daysCount += addedDays;
		thisCopy.AddDays(addedDays);
	}

	while (thisCopy.month > date.month)
	{
		int addedDays = thisCopy.MonthLenght();
		daysCount -= addedDays;
		thisCopy.RemoveDays(addedDays);
	}

	daysCount += date.day - thisCopy.day;

	return daysCount;
}

int Date::DaysToNewYear()
{
	Date newYear(1, 1, year + 1);

	return this->DaysTo(newYear);
}

int Date::DaysToXmas()
{
	Date xmas(25, 12, year);

	if (this->IsBefore(xmas))
	{
		return this->DaysTo(xmas);
	}

	Date nextXmas(25, 12, year + 1);

	return this->DaysTo(nextXmas);
}

//Returns true if the parameter date is after this date
bool Date::IsBefore(const Date& date)
{
	if (year < date.year)
	{
		return true;
	}
	else if (year > date.year) 
	{
		return false;
	}

	if (month < date.month)
	{
		return true;
	}
	else if (month > date.month)
	{
		return false;
	}

	return day < date.day;
}

//private functions

//Operations

void Date::Copy(const Date& date)
{
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

int Date::MonthLenght()
{
	if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
	{
		return 30;
	}

	if (this->month == 2)
	{
		if (this->IsLeapYear())
		{
			return 29;
		}

		return 28;
	}

	return 31;
}