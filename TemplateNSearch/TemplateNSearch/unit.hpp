// unit.hpp

#ifndef UINT_HPP_INCLUDED
#define UINT_HPP_INCLUDED

#include <iostream>
#include <string>

template <class T>
bool are_equal(T a, T b)
{
	return a == b;
}

template <class T>
bool verify(T expected, T got, const std::string& message)
{
	if (are_equal(expected, got))
	{
		std::cout << "Passed: " << message << std::endl;
		return true;
	}
	std::cout << "Failed! Expected: " << expected << " Got: " << got <<
		" - " << message << std::endl;
	return false;
}

#endif // UINT_HPP_INCLUDED