# Problem 2
This program represents a simple system for automation testing 

## TestSuite
Every test suite has a name and a set of test cases and it can:
* add new test case
* filter passing test cases
* filter failing test cases
* filter test cases by their error type
* remove all test cases with certain error type

## TestCase
Every test case has a name and it can:
* check if it is passing
* check if it has an error
* get it's error type
* get it's error message

## Error
Every error has a type, a message and it can:
* get it's type
* check if it has a message
* get it's message if there is any
* create new Error (for all error types)
