#include"string.h"

size_t String::size()const{ return mLength; }

size_t String::length()const{ return mLength; }

size_t String::max_size()const
{
	return (size_t)pow(2, 32) - 1;
}

void String::resize(size_t n)
{
	resize(n, '\0');
}

void String::resize(size_t n, char c)
{
	if (n == npos || n > max_size())
	{
		throw"length_error";
	}

	if (n < mLength)
	{
		str[n] = '\0';
	}
	else
	{
		if (n> mCapacity)
		{
			reserve(n + 1);
		}
		size_t i = mLength;
		while (i <= n)
		{
			str[i] = c;
			i++;
		}
		str[n] = '\0';
	}
	mLength = n;
}

size_t String::capacity()const{ return mCapacity; }

void String::reserve(size_t newSize)
{

	if (newSize == mCapacity){ return; }
	if (newSize < mCapacity){ newSize = mCapacity; }
	char* largerArr = new char[newSize];
	memmove(largerArr, str, mLength);
	delete[] str;
	str = largerArr;
	mCapacity = newSize;

}

void String::clear()
{

	if (str != NULL)
	{
		mLength = 0;
		delete[] str;
	}
	str = emptyStr;
}

bool String::empty()const{ return (this->size() == 0); }

void String::shrink_to_fit()
{
	char* fitArr = new char[mLength];
	memmove(fitArr, str, mLength);
	delete[] str;
	str = fitArr;
	mCapacity = mLength;
}