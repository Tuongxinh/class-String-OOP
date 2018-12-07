#include"string.h"

const char* String::c_str()const{ return str; }

const char* String::data()const{ return str; }

size_t String::copy(char* s, size_t len, size_t pos) const
{

	if (pos >= mLength)
	{
		throw "out_of_range";
	}
	else //pos<mLength
	{
		if (len >= mLength)
		{
			String resultCopyStr(*this, pos, mLength - pos);
			strcpy(s, resultCopyStr.str);
			return mLength - pos;
		}
		else
		{
			String resultCopyStr(*this, pos, len);
			strcpy(s, resultCopyStr.str);
			return len;
		}
	}

}

//Phuong thuc FIND
size_t String::find(const String& inputStr, size_t pos)const
{
	if (inputStr == NULL){ return npos; }
	if (*inputStr.str == '\0'){ return pos > mLength ? npos : pos; }
	if (pos > mLength - 1 || mLength == 0){ return npos; }

	char* resultSubStr = strstr(str + pos, inputStr.str);
	if (resultSubStr == NULL){ return npos; }
	return (mLength - strlen(resultSubStr));
}

size_t String::find(const char* inputStr, size_t pos)const
{
	String str(inputStr);
	return find(str, pos);
}

size_t String::find(char c, size_t pos)const
{
	if (c == NULL){ return npos; }
	if (c == '\0'){ return pos > mLength ? npos : pos; }
	if (mLength == 0 || pos > mLength - 1){ return npos; }

	for (size_t i = pos; i < mLength; i++)
	{
		if (str[i] == c){ return i; }
	}
	return npos;
}

size_t String::find(const char* s, size_t pos, size_t n) const
{
	String str(s, 0, n);
	return find(str, pos);
}
//

size_t String::rfind(const String& inputStr, size_t pos) const
{
	if (inputStr == NULL){ return npos; }

	if (pos == npos || pos > mLength)
	{
		pos = mLength;
	}
	String tmp(str, 0, pos);

	_strrev(tmp.str);
	char* tmpInputStr = new char[inputStr.length() + 1];
	strcpy(tmpInputStr, inputStr.str);

	size_t idx_rfind = tmp.find(_strrev(tmpInputStr));
	if (idx_rfind == npos){ return npos; }

	delete[] tmpInputStr;
	return  tmp.mLength - idx_rfind - inputStr.length();
}

size_t String::rfind(const char* inputStr, size_t pos) const
{
	String str(inputStr);
	return rfind(str, pos);
}

size_t String::rfind(const char* inputStr, size_t pos, size_t n) const
{
	String str(inputStr, 0, n);
	return rfind(str, pos);
}

size_t String::rfind(char c, size_t pos) const
{
	if (c == NULL){ return npos; }
	if (pos > mLength || pos == npos){ pos = mLength; }

	String newStr(str, 0, pos);
	_strrev(newStr.str);
	int idx_find = newStr.find(c);
	if (idx_find == npos){ return npos; }
	return newStr.mLength - idx_find - 1;
}

size_t String::find_first_of(const char* inputStr, size_t pos) const
{
	if (inputStr == NULL){ return npos; }
	if (*inputStr == '\0'){ return pos > mLength ? npos : pos; }
	if (pos > mLength - 1 || mLength == 0){ return npos; }

	for (size_t i = pos; i < mLength; i++)
	{
		for (size_t j = 0; j < strlen(inputStr); j++)
		{
			if (str[i] == inputStr[j])
			{
				return i;
			}
		}
	}
	return npos;
}

size_t String::find_first_of(const String& inputStr, size_t pos) const
{
	return find_first_of(inputStr.str, pos);
}

size_t String::find_first_of(char c, size_t pos) const
{
	return find(c, pos);
}

size_t String::find_first_of(const char* s, size_t pos, size_t n) const
{
	if (s == NULL){ return npos; }
	String newS(s, 0, n);
	return find_first_of(newS.str, pos);
}




size_t String::find_last_of(const char* inputStr, size_t pos) const
{
	String newStr(inputStr);
	return find_last_of(newStr, pos);

}

size_t String::find_last_of(const String& inputStr, size_t pos)const
{
	if (inputStr == NULL){ return npos; }

	if (pos > mLength - 1 || pos == npos)
	{
		pos = mLength - 1;
	}

	for (size_t i = pos; i >= 0; i--)
	{
		for (size_t j = 0; j < strlen(inputStr.str); j++)
		{
			if (str[i] == inputStr[j])
			{
				return i;
			}
		}
	}
	return npos;
}

size_t String::find_last_of(char c, size_t pos)const
{
	if (c == NULL){ return npos; }
	if (pos>mLength - 1 || pos == npos){ pos = mLength - 1; }

	for (int i = pos; i >= 0; i--)
	{
		if (str[i] == c){ return i; }
	}
	return npos;
}

size_t String::find_last_of(const char* s, size_t pos, size_t n) const
{

	String newS(s, 0, n);
	return find_last_of(newS, pos);
}



size_t String::find_first_not_of(const String& s, size_t pos) const
{
	if (s == NULL || pos>mLength - 1){ return npos; }
	size_t count = 0;
	for (size_t i = pos; i < mLength; i++)
	{
		for (size_t j = 0; j < s.length(); j++)
		{
			if (str[i] != s[j])
			{
				count++;
			}
			else{ continue; }

		}
		if (count == s.length())
		{
			return i;
		}
	}
	return npos;
}

size_t String::find_first_not_of(const char* s, size_t pos) const
{
	String newS(s);
	return find_first_not_of(newS, pos);
}

size_t String::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	String newS(s, 0, n);
	return find_first_not_of(newS, pos);
}

size_t String::find_first_not_of(char c, size_t pos) const
{
	if (c == NULL || pos > mLength - 1){ return npos; }
	for (size_t i = 0; i < mLength; i++)
	{
		if (str[i] != c)
		{
			return i;
		}
	}
	return npos;
}


size_t String::find_last_not_of(const String& s, size_t pos) const
{
	if (s == NULL){ return npos; }
	if (pos>mLength - 1 || pos == npos){ pos = mLength - 1; }

	size_t count = 0;
	for (size_t i = pos; i >= 0; i--)
	{
		for (size_t j = 0; j < s.length(); j++)
		{
			if (str[i] != s[j])
			{
				count++;
			}
			else{ continue; }

		}
		if (count == s.length())
		{
			return i;
		}
	}
	return npos;
}

size_t String::find_last_not_of(const char* s, size_t pos) const
{
	String str(s);
	return find_last_not_of(str, pos);
}

size_t String::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	String str(s, 0, n);
	return find_last_not_of(s, pos);
}

size_t String::find_last_not_of(char c, size_t pos) const
{
	if (c == NULL){ return npos; }
	for (int i = pos; i >= 0; i--)
	{
		if (str[i] != c){ return i; }
	}
	return npos;
}

String& String::substr(size_t pos, size_t len)const
{
	return String(str, pos, len);
}

int String::compare(const char* inputStr)const
{
	if (inputStr == NULL)return 1;
	return strcmp(str, inputStr);
}

int String::compare(const String& inputStr)const
{
	return compare(inputStr.str);
}





