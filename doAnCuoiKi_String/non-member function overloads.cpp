#include"string.h"

String operator+(const String& left, const String& right)
{
	return String(left).append(right);
}

String operator+(const String& left, const char *right)
{
	return String(left).append(right);
}

String operator+(const char *left, const String& right)
{
	return String(left).append(right);
}

String operator+(const String& left, char right)
{
	return String(left).operator+=(right);
}

String operator+(char left, const String& right)
{
	return String(&left, 1).append(right);
}

//relational operators (string)

bool operator==(const String& l, const String& r)
{
	if (&l == &r){ return 1; }
	else{
		return strcmp(l.str, r.str) == 0;
	}
}

bool operator==(const char* l, const String& r)
{
	if (r == NULL || l == NULL){ return 0; }
	return strcmp(l, r.str) == 0;
}

bool operator==(const String& l, const char* r)
{
	return r == l;
}

bool operator!=(const string& l, const string& r)
{
	return !(r == l);
}

bool operator!=(const string& l, const char* r)
{
	return !(r == l);
}

bool operator!=(const char* l, const string& r)
{
	return !(r == l);
}

bool operator<  (const String& lhs, const String& rhs)
{
	if (strcmp(lhs.str, rhs.str) == -1)return true;
	return false;
}

bool operator<  (const char*   lhs, const String& rhs)
{
	if (strcmp(lhs, rhs.str) == -1)return true;
	return false;
}

bool operator<  (const String& lhs, const char*   rhs)
{
	if (strcmp(lhs.str, rhs) == -1)return true;
	return false;
}

bool operator<= (const String& lhs, const String& rhs)
{
	if (lhs.str == rhs.str){ return true; }
	if (strcmp(lhs.str, rhs.str) == -1)return true;
	return false;
}

bool operator<= (const char*   lhs, const String& rhs)
{
	if (lhs == rhs.str){ return true; }
	if (strcmp(lhs, rhs.str) == -1)return true;
	return false;
}

bool operator<= (const String& lhs, const char*   rhs)
{
	if (lhs.str == rhs){ return true; }
	if (strcmp(lhs.str, rhs) == -1)return true;
	return false;
}

bool operator>  (const String& lhs, const String& rhs)
{
	if (lhs.str == rhs.str){ return true; }
	if (strcmp(lhs.str, rhs.str) == 1)return true;
	return false;
}

bool operator>  (const char*   lhs, const String& rhs)
{
	if (lhs == rhs.str){ return true; }
	if (strcmp(lhs, rhs.str) == -1)return true;
	return false;
}

bool operator>  (const String& lhs, const char*   rhs)
{
	if (lhs.str == rhs){ return true; }
	if (strcmp(lhs.str, rhs) == -1)return true;
	return false;
}

bool operator>= (const String& lhs, const String& rhs)
{
	if (lhs.str == rhs.str){ return true; }
	if (strcmp(lhs.str, rhs.str) == -1)return true;
	return false;
}

bool operator>= (const char*   lhs, const String& rhs)
{
	if (lhs == rhs.str){ return true; }
	if (strcmp(lhs, rhs.str) == -1)return true;
	return false;
}

bool operator>= (const String& lhs, const char*   rhs)
{
	if (lhs.str == rhs){ return true; }
	if (strcmp(lhs.str, rhs) == -1)return true;
	return false;
}

void swap(String& x, String& y)
{
	x.swap(y);
}

istream& operator>>(istream& inDev, String& str)
{
	char buffer[100];
	inDev >> buffer;

	str.mLength = strlen(buffer);
	str.str = new char[str.mLength + 1];
	strcpy(str.str, buffer);

	return inDev;
}

ostream& operator<< (ostream& outDev, const String& str)
{
	outDev << str.str;
	return outDev;
}

istream& getline(istream& inDev, String& str, char delim)
{
	const int n = 256;
	char buffer[n];
	inDev.get(buffer, n, delim);

	str.mLength = strlen(buffer);
	str.str = new char[str.mLength + 1];
	strcpy(str.str, buffer);

	return inDev;
}

istream& getline(istream& inDev, String& str)
{
	return getline(inDev, str, '\n');
}
