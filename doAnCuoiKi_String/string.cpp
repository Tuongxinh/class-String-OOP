#include"string.h"

void String::constructor()
{
	this->mLength = 0;
	this->mCapacity = INITIAL_SIZE;
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
	delete[] str;
}

bool String::empty(){ return (this->size() == 0); }

size_t String::capacity()const{ return mCapacity; }

char* String::data(){ return str; }

void String::clear()
{
	mLength = mCapacity = 0;
	if (str != NULL)
	{
		delete[]str;
	}
	str = emptyStr;
}

size_t String::length()const{ return mLength; }

size_t String::size(){ return mLength; }

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
			str[i]=c;
			i++;
		}
		str[n] = '\0';
	}
	mLength = n;
}

size_t String::max_size()const
{
	return (size_t)pow(2,32)-1;
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
	if (mLength == 0 || pos > mLength -1){ return npos; }

	for (int i = pos; i < mLength; i++)
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

char* String::c_str(){ return str; }

String& String::substr(size_t pos, size_t len)const
{
	return String(str, pos, len);
}

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



size_t String::find_first_of(const char* inputStr, size_t pos) const
{
	if (inputStr == NULL){ return npos; }
	if (*inputStr == '\0'){ return pos > mLength ? npos : pos; }
	if (pos > mLength - 1 || mLength == 0){ return npos; }

	for (int i = pos; i < mLength; i++)
	{
		for (int j = 0; j < strlen(inputStr); j++)
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

	for (int i = pos; i >= 0; i--)
	{
		for (int j = 0; j < strlen(inputStr.str); j++)
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



size_t String::find_first_not_of(const String& s, size_t pos ) const
{
	if (s == NULL || pos>mLength - 1){ return npos; }
	size_t count = 0;
	for (int i = pos; i < mLength; i++)
	{
		for (int j = 0; j < s.length(); j++)
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

size_t String::find_first_not_of(const char* s, size_t pos ) const
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
	for (int i = 0; i < mLength; i++)
	{
		if (str[i] != c)
		{
			return i;
		}
	}
	return npos;
}


size_t String::find_last_not_of(const String& s, size_t pos ) const
{
	if (s == NULL ){ return npos; }
	if (pos>mLength - 1 || pos == npos){ pos = mLength - 1; }

	size_t count = 0;
	for (int i = pos; i >=0; i--)
	{
		for (int j = 0; j < s.length(); j++)
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

size_t String::find_last_not_of(const char* s, size_t pos ) const
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



int String::compare(const char* inputStr)const
{
	if (inputStr == NULL)return 1;
	return strcmp(str, inputStr);
}

int String::compare(const String& inputStr)const
{
	return compare(inputStr.str);
}


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

void String::push_back(const char c)
{	
	if (mLength + 2 > mLength)
	{
		const size_t newLength = mLength + 1;
		if (newLength > mCapacity)
		{
		reserve(newLength+1);
		}

		str[mLength] = c;
		++mLength;
		str[mLength] = '\0';
	}
	
}

void String::pop_back()
{
	if (str == NULL){ return; }
	erase(mLength - 1, 1);
}

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

void String::shrink_to_fit()
{
	char* fitArr = new char[mLength];
	memmove(fitArr, str, mLength);
	delete[] str;
	str = fitArr;
	mCapacity = mLength;
}



size_t String::rfind(const String& inputStr, size_t pos) const
{
	if (inputStr == NULL){ return npos; }

	if (pos == npos || pos > mLength)
	{
		pos = mLength;
	}
	String tmp(str, 0, pos);

	strrev(tmp.str);
	char* tmpInputStr = new char[inputStr.length() + 1];
	strcpy(tmpInputStr, inputStr.str);

	size_t idx_rfind = tmp.find(strrev(tmpInputStr));
	if (idx_rfind == npos){ return npos; }

	delete[] tmpInputStr;
	return  tmp.mLength - idx_rfind -inputStr.length();
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
	strrev(newStr.str);
	int idx_find = newStr.find(c);
	if (idx_find == npos){ return npos; }
	return newStr.mLength - idx_find - 1;
}



String& String::INSERT(size_t pos, const char* s)
{
	int i = mLength;
	int j;

	this->resize(mLength + strlen(s));

	if (mLength > mCapacity){ this->reserve(mLength + 2); }

	j = 1;
	for (i; i >= pos; i--)
	{
		str[mLength - j] = str[i];
		j++;
	}

	j = 0;
	for (int i = pos; i < pos + strlen(s); i++)
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



String& String::replace(size_t pos, size_t len, const String& str)
{
	if (str.str == NULL){ return *this; }
	if (len > mLength){ throw "out_of_range"; }

	erase(pos, len);
	return insert(pos, str);
}

String& String::replace(size_t pos, size_t len, const String& str, size_t subpos, size_t sublen)
{
	String myStr(str,subpos,sublen);
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

 bool operator<  (const String& lhs, const String& rhs)
 {
	 return lhs.compare(rhs);
 }

 bool operator<  (const char*   lhs, const String& rhs)
 {
	 return strcmp(lhs, rhs.str)==-1;
 }

 bool operator<  (const String& lhs, const char*   rhs)
 {
	 return strcmp(lhs.str, rhs) == -1;
 }

 bool operator<= (const String& lhs, const String& rhs)
 {
	 if (lhs.str == rhs.str){ return 1; }
	 return strcmp(lhs.str, rhs.str) == -1;
 }

 bool operator<= (const char*   lhs, const String& rhs)
 {
	 if (lhs == rhs.str){ return 1; }
	 return strcmp(lhs, rhs.str) == -1;
 }

 bool operator<= (const String& lhs, const char*   rhs)
 {
	 if (lhs.str == rhs){ return 1; }
	 return strcmp(lhs.str, rhs) == -1;
 }

 bool operator>  (const String& lhs, const String& rhs)
 {
	 return strcmp(lhs.str, rhs.str) == 1;
 }

 bool operator>  (const char*   lhs, const String& rhs)
 {
	 return strcmp(lhs, rhs.str) == 1;
 }

 bool operator>  (const String& lhs, const char*   rhs)
 {
	 return strcmp(lhs.str, rhs) == 1;
 }

 bool operator>= (const String& lhs, const String& rhs)
 {
	 if (lhs.str == rhs.str){ return 1; }
	 return strcmp(lhs.str, rhs.str) == 1;
 }

 bool operator>= (const char*   lhs, const String& rhs)
 {
	 if (lhs == rhs.str){ return 1; }
	 return strcmp(lhs, rhs.str) == 1;
 }

 bool operator>= (const String& lhs, const char*   rhs)
 {
	 if (lhs.str == rhs){ return 1; }
	 return strcmp(lhs.str, rhs) == 1;
 }

 void swap(String& x, String& y)
 {
	 x.swap(y);
 }

 String::iterator String::begin()
 {
	 return iterator(str);
 }

  const String:: const_iterator String::begin()const
 {
	 return str;
 }

  String::iterator String::end()
  {
	  return iterator(str + mLength);
  }

  const String::const_iterator String::end()const
  {
	  return str + mLength;
  }

  String::reverse_iterator String::rbegin()
  {
	  return reverse_iterator(str + mLength - 1);
  }

  const String::const_reverse_iterator String::rbegin() const
  {
	  return str + mLength - 1;
  }

  String::reverse_iterator String::rend()
  {
	  return reverse_iterator(str - 1);
  }

  const String::const_reverse_iterator String::rend() const
  {
	  return str - 1;
  }

 