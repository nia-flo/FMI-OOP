#include "Document.hpp"
#include "KeyValueDatabase.hpp"

#include <iostream>

void testDocument()
{
	Document temp("temp", "/tmp", "doc");

	temp.write_line("This is an example doc");
	temp.write_line("This is another example line");
	temp.write_line("This is a third example line");
	temp.write_line("This is a forth example line");

	std::cout << temp.read_line() << std::endl; //This is an example doc
	std::cout << temp.read_line() << std::endl; //This is another example line

	std::cout << temp.read_line(3) << std::endl; //This is a third example line
	std::cout << temp.read_line() << std::endl; //This is a forth example line

	try
	{
		std::cout << temp.read_line() << std::endl;
	}
	catch (std::out_of_range ex)
	{
		std::cout << ex.what() << '\n';
	}

	try
	{
		std::cout << temp.read_line(0) << std::endl;
	}
	catch (std::out_of_range ex)
	{
		std::cout << ex.what() << '\n';
	}

	std::cout << temp.read_line(1) << std::endl; //This is an example doc
	std::cout << temp.read_line() << std::endl; //This is another example line

	std::cout << '\n' << temp.to_string() << '\n' << temp.debug_print() << '\n';

}

void testKeyValueDatabase()
{
	KeyValueDatabase db("KeyValueDatabase db", "C", "db");
	
	db.add_entry({ "first", 1 });
	db.add_entry({ "second", 3 });
	db.add_entry({ "pesho", 123 });

	try 
	{
		db.add_entry({ "first", 1 });
	}
	catch (std::invalid_argument ex)
	{
		std::cout << ex.what() << '\n';
	}

	std::cout << '\n' << db.to_string() << '\n' << db.debug_print() << '\n';

}

int main()
{
	testDocument();

	testKeyValueDatabase();

	Document doc("ToDo", "D:/files", "txt");
	KeyValueDatabase db("baza", "C:\bazi\test", "db");

	std::cout << (doc == doc);
	std::cout << (db == db);

	Comparable* docComp = static_cast<Comparable*>(&doc);

	std::cout << (docComp == docComp) << '\n';
	std::cout << (doc == docComp) << '\n';
	std::cout << (db == docComp) << '\n';
	std::cout << "mina\n";

	std::string newDocStr = "new doc name\nnew doc loc\nnew doc ext\nline1\nline2\nline3\n";
	doc.from_string(newDocStr);

	return 0;
}