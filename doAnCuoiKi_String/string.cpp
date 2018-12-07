#define _CRT_SECURE_NO_WARNINGS
#include"string.h"

void String::constructor()
{
	this->mLength = 0;
	this->mCapacity = 0;
	str = emptyStr;
}

void String::constructor(const char* strInstance, size_t pos, size_t len)
{
	str = new char[len + 1];
	if (str)
	{
		this->mLength = len;
		this->mCapacity = len;
		memcpy(str, strInstance + pos, len);
		str[mLength] = '\0';
		return;
	}
	constructor();
}

void String::constructor(size_t len, char c)
{
	str = new char[len + 1];
	if (str)
	{
		mLength = len;
		mCapacity = len;
		memset(str, c, len);
		return;
	}
	constructor();
}

String::String()
{
	constructor();
}

String::String(const char* strInstance)
{
	if (strInstance)
	{
		constructor(strInstance, 0, strlen(strInstance));
		return;

	}
	constructor();
}

String::String(const char* strInstance, size_t len)
{
	if (len != npos)
	{
		constructor(strInstance, 0, len);
		return;
	}

	constructor();

}

String::String(const String& strInstance, size_t pos, size_t len)
{
	if (pos < strInstance.mLength)
	{
		if (len == npos)
		{
			constructor(strInstance.str, pos, strInstance.mLength - pos);
			return;
		}
		else if (len <= strInstance.mLength - pos)
		{
			constructor(strInstance.str, pos, len);
			return;
		}
	}
	constructor();
}

String::String(size_t size, char c)
{
	constructor(size, c);
}

String::~String()
{
	/*delete[] str;*/
}

String& String::operator=(const String& str)
{
	return assign(str);
}

String& String::operator=(const char* str)
{
	return assign(str);
}

String& String::operator=(char c)
{
	return assign(1, c);
}
