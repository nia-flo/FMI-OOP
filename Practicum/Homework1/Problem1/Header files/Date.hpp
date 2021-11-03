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

#pragma once

class Date 
{
public:
	Date(); //Default Constructor
	Date(int, int, int); //Constructor
	Date(const Date&); //Copy Constructor

	Date& operator=(const Date&); //Copy assignment operator

	~Date(); //Destructor

	//Accessors
	int GetDay();
	int GetMonth();
	int GetYear();

	//Operations
	void AddDays(int);
	void RemoveDays(int);
	bool IsLeapYear();
	int DaysToXmas();
	int DaysToNewYear();
	int DaysTo(const Date&);
	bool IsBefore(const Date&); 

private:
	//Properties
	int day;
	int month;
	int year;

	//Operations
	void Copy(const Date&);
	int MonthLenght();
};