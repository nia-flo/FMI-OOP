#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error)
{
	this->name = name;
	this->error = error;
}

TestCase::TestCase(const TestCase& testCase)
{
	this->Copy(testCase);
}

TestCase& TestCase::operator=(const TestCase& testCase)
{
	this->Copy(testCase);

	return *this;
}

std::string TestCase::getName() const
{
	return this->name;
}

bool TestCase::isPassing() const
{
	return (this->error.getType() == ErrorType::None || this->error.getType() == ErrorType::Warning);
}

bool TestCase::hasError() const
{
	return (this->error.getType() != ErrorType::None);
}

ErrorType TestCase::getErrorType() const
{
	return this->error.getType();
}

std::string TestCase::getErrorMessage() const
{
	return this->error.getMessage();
}

void TestCase::Copy(const TestCase& testCase)
{
	this->error = testCase.error;
	this->name = testCase.name;
}
