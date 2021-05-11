#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
public:
    Result() = default;
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const Error&) const;
    bool operator==(const T&) const;

private:
    Optional<T> result;
    Optional<Error> error;
};

template<typename T>
Result<T>::Result(const T& result)
{
    Optional<T> optionalResult(result);
    this->result = optionalResult;
}

template<typename T>
Result<T>::Result(const std::string& error_message)
{
    Error error(error_message);
    Optional<Error> optionalError(error);
    this->error = optionalError;
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return this->result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
    return this->error;
}

template<typename T>
bool Result<T>::operator==(const Error&) const
{
    return !this->error.is_none();;
}

template<typename T>
bool Result<T>::operator==(const T&) const
{
    return !this->result.is_none();;
}
