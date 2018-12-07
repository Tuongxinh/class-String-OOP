#include"string.h"

const char& String::operator[](const size_t pos) const
{
	if (pos > mLength)return str[mLength];
	return str[pos];
}

char& String::operator[](const size_t pos)
{
	if (pos > mLength)return str[mLength];
	return str[pos];
}

char& String::at(size_t pos)
{
	if (pos > mLength)
	{
		throw "out_of_range";
	}
	else{
		return str[pos];
	}
}

const char& String::at(size_t pos) const
{
	if (pos > mLength)
	{
		throw "out_of_range";
	}
	else{
		return str[pos];
	}
}

char& String::front()
{
	return str[0];
}

const char& String::front() const
{
	return str[0];
}

char& String::back()
{
	return str[mLength - 1];
}

const char& String::back() const
{
	return str[mLength - 1];
}