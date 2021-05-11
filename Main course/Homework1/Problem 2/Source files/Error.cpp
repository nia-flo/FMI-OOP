#pragma warning (disable : 4996)

#include "Error.hpp"

Error::Error()
{
	this->message = nullptr;
}

Error::Error(ErrorType type, const char* message = "")
{
	this->type = type;
	this->setMessage(message);
}

Error::Error(const Error& error)
{
	this->Copy(error);
}

Error& Error::operator=(const Error& error)
{
	delete[] this->message;

	this->Copy(error);

	return *this;
}

Error::~Error()
{
	delete[] this->message;
}

bool Error::hasMessage() const
{
	return (this->type != ErrorType::None);
}

const char* Error::getMessage() const
{
	if (this->type == ErrorType::None)
	{
		return nullptr;
	}

	return this->message;
}

ErrorType Error::getType() const
{
	return this->type;
}

Error Error::newNone()
{
	Error error(ErrorType::None);

	return error;
}

Error Error::newBuildFailed(const char* message)
{
	Error error(ErrorType::BuildFailed, message);

	return error;
}

Error Error::newWarning(const char* message)
{
	Error error(ErrorType::Warning, message);

	return error;
}

Error Error::newFailedAssertion(const char* message)
{
	Error error(ErrorType::FailedAssertion, message);

	return error;
}

void Error::setMessage(const char* message)
{
	this->message = new char[strlen(message) + 1];
	strcpy(this->message, message);
}

void Error::Copy(const Error& error)
{
	this->type = error.type;
	this->setMessage(error.message);
}
