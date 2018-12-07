#include"string.h"

String& String::operator+=(const String& s)
{
	return append(s);
}

String& String::operator+= (const char* s)
{
	return append(s);
}

String& String::operator+=(const char c)
{
	push_back(c);
	return *this;
}

String& String::append(const char* s, size_t num)
{
	if (s != NULL)
	{
		const size_t total_len = mLength + num;
		if (num > 0 && total_len + 1 > mLength)
		{
			if (total_len > mCapacity)
			{
				reserve(total_len + 2);
			}

			memcpy(str + mLength, s, num);
			mLength = total_len;
			str[mLength] = '\0';
		}
	}
	return *this;
}

String& String::append(const char* s)
{
	return append(s, strlen(s));
}

String& String::append(const String& s)
{
	return append(s.str, s.mLength);
}

String& String::append(const String& s, size_t subpos, size_t sublen)
{
	return append(s.str + subpos, sublen);
}

String& String::append(size_t num, char c)
{
	return append(c, 1);
}

void String::push_back(const char c)
{
	if (mLength + 2 > mLength)
	{
		const size_t newLength = mLength + 1;
		if (newLength > mCapacity)
		{
			reserve(newLength + 1);
		}

		str[mLength] = c;
		++mLength;
		str[mLength] = '\0';
	}

}


String& String::assign(const String& s)
{
	clear();
	constructor(s.str, 0, s.mLength);
	return *this;
}

String& String::assign(const String& s, size_t subpos, size_t sublen)
{
	if (sublen > mLength){ return *this; }
	if (sublen < s.mLength - subpos)
	{
		clear();
		constructor(s.str, subpos, sublen);
	}
	return *this;

}

String& String::assign(const char* s)
{
	if (s == NULL){ return *this; }

	clear();
	constructor(s, 0, strlen(s));
	return *this;
}

String& String::assign(const char* s, size_t n)
{
	if (s == NULL || n == 0){ return *this; }

	clear();
	constructor(s, n);
	return *this;
}

String& String::assign(size_t n, char c)
{
	if (n == 0 || c == NULL){ return *this; }

	clear();
	constructor(n, c);
	return *this;
}

String& String::INSERT(size_t pos, const char* s)
{
	size_t i = mLength;
	size_t j;

	this->resize(mLength + strlen(s));

	if (mLength > mCapacity){ this->reserve(mLength + 2); }

	j = 1;
	for (i; i >= pos; i--)
	{
		str[mLength - j] = str[i];
		j++;
	}

	j = 0;
	for (size_t i = pos; i < pos + strlen(s); i++)
	{
		str[i] = s[j];
		j++;
	}

	return *this;
}

String& String::insert(size_t pos, const String& str)
{
	return INSERT(pos, str.str);
}

String& String::insert(size_t pos, const String& str, size_t subpos, size_t sublen)
{
	if (str.str == NULL){ return *this; }
	if (pos > mLength){ throw "out_of_range"; }

	String newS(str, subpos, sublen);

	return INSERT(pos, newS.str);
}

String& String::insert(size_t pos, const char* s)
{

	if (s == NULL){ return *this; }
	if (pos > mLength){ throw "out_of_range"; }

	return INSERT(pos, s);

}

String& String::insert(size_t pos, const char* s, size_t n)
{
	if (s == NULL){ return *this; }
	if (pos > mLength){ throw "out_of_range"; }

	String newS(s, 0, n);
	return INSERT(pos, newS.str);
}

String& String::insert(size_t pos, size_t n, char c)
{

	if (c == NULL){ return *this; }
	if (pos > mLength){ throw "out_of_range"; }

	String newS(n, c);
	return INSERT(pos, newS.str);
}

String& String::erase(size_t pos, size_t n)
{
	if (pos > mLength || n == 0){ return *this; }
	const size_t remainder = pos + n;

	if (remainder >= mLength || remainder < pos)
	{
		str[pos] = '\0';
		mLength = pos;
		return *this;
	}

	size_t left = mLength - remainder + 1;
	memmove(str + pos, str + remainder, left);
	mLength = mLength - n;
	return *this;
}

String& String::replace(size_t pos, size_t len, const String& str)
{
	if (str.str == NULL){ return *this; }
	if (len > mLength){ throw "out_of_range"; }

	erase(pos, len);
	return insert(pos, str);
}

String& String::replace(size_t pos, size_t len, const String& str, size_t subpos, size_t sublen)
{
	String myStr(str, subpos, sublen);
	return replace(pos, len, str);
}

String& String::replace(size_t pos, size_t len, const char* s)
{
	String str(s);
	return replace(pos, len, str);
}

String& String::replace(size_t pos, size_t len, const char* s, size_t n)
{
	String str(s, 0, n);
	return replace(pos, len, str);
}

void String::swap(String& other)
{
	if (this == &other){ return; }

	char* temp = str;
	const size_t temp_mCapicity = mCapacity;
	const size_t temp_mLength = mLength;

	str = other.str;
	mCapacity = other.mCapacity;
	mLength = other.mLength;

	other.str = temp;
	other.mCapacity = temp_mCapicity;
	other.mLength = temp_mLength;


}

void String::pop_back()
{
	if (str == NULL){ return; }
	erase(mLength - 1, 1);
}