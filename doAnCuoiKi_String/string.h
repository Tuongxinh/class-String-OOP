#ifdef _NOEXCEPT
#define noexcept _NOEXCEPT
#endif

#define _CRT_SECURE_NO_WARNIGNS
#ifndef __STRING_H__
#define __STRING_H__




#include <algorithm>
#include<limits>
#include<iostream>
#include<cmath>
#include<string.h>
#include<iterator>
#include<iomanip>
#include"iterator.h"



#define INITIAL_SIZE 15
using namespace std;

namespace {
	char emptyStr[1] = { '\0' };
}

class String
{
private:
	char* str;
	size_t mCapacity;
	size_t mLength;

	void constructor();
	void constructor(const char*, size_t pos = 0, size_t len = npos);
	void constructor(size_t, char c = 0);
	

public:
	
	static const size_t npos = static_cast<size_t>(-1) - 1;
	////////// constructor
	String();
	String(const char*);
	String(const char*, size_t num);
	String(const String&, size_t pos = 0, size_t num = npos);
	String(size_t, char c = 0);


	////////// Iterators
	CT::iterator begin();
	const CT::const_iterator begin()const;

	CT::iterator end();
	const CT::const_iterator end()const;

	CT::reverse_iterator rbegin();
	const CT::const_reverse_iterator rbegin() const;

	CT::reverse_iterator rend();
	const CT::const_reverse_iterator rend() const;

	CT::const_iterator cbegin() const noexcept;

	CT::const_iterator cend() const noexcept;

	CT::const_reverse_iterator crbegin() const noexcept;

	CT::const_reverse_iterator crend() const noexcept;



	////////// capacity
	size_t size()const;

	size_t length()const;

	size_t max_size() const;

	void resize(size_t n);
	void resize(size_t n, char c);

	size_t capacity()const;

	void reserve(size_t newSize = 0);

	void clear();

	bool empty()const;
	
	void shrink_to_fit();

	
	////////// element access
	const char& operator[](const size_t pos) const;
	char& operator[](const size_t pos);

	char& at(size_t pos);
	const char& at(size_t pos) const;


	char& back();
	const char& back() const;

	char& front();
	const char& front() const;
	

	///////// Modifiers:
	String& operator+= (const String& str);
	String& operator+= (const char* s);
	String& operator+= (const char c);

	String& append(const String& str);
	String& append(const char* s);
	String& append(const char* s, size_t num);
	String& append(const String& str, size_t subpos, size_t sublen);
	String& append(size_t num, char c);
	/*template<class InputIterator>
	String& append(InputIterator first, InputIterator last);
*/
	void push_back(const char c);

	String& assign(const String& str);
	String& assign(const String& str, size_t subpos, size_t sublen);
	String& assign(const char* s);
	String& assign(const char* s, size_t n);
	String& assign(size_t n, char c);
	/*template<class InputIterator>
	String& assign(InputIterator first, InputIterator last);*/

	String& INSERT(size_t pos, const char* s);
	String& insert(size_t pos, const String& str);
	String& insert(size_t pos, const String& str, size_t subpos, size_t sublen);
	String& insert(size_t pos, const char* s);
	String& insert(size_t pos, const char* s, size_t n);
	String& insert(size_t pos, size_t n, char c);
	void insert(CT::iterator p, size_t n, char c);
	CT::iterator insert(CT::iterator p, char c);
	template<class inputIterator>
	void insert(CT::iterator p, inputIterator first, inputIterator last);

	String& erase(size_t pos = 0, size_t n = npos);
	CT::iterator erase(CT::iterator p);
	CT::iterator erase(CT::iterator first, CT::iterator last);

	String& replace(size_t pos, size_t len, const String& str);
	//String& replace(iterator i1, iterator i2, const String& str);
	String& replace(size_t pos, size_t len, const String& str, size_t subpos, size_t sublen);
	String& replace(size_t pos, size_t len, const char* s);
	//String& replace(iterator i1, iterator i2, const char* s);
	String& replace(size_t pos, size_t len, const char* s, size_t n);
	//String& replace(iterator i1, iterator i2, const char* s, size_t n);
	String& replace(size_t pos, size_t len, size_t n, char c);
	//String& replace(iterator i1, iterator i2, size_t n, char c);
	/*template <class InputIterator>
	string& replace(iterator i1, iterator i2,InputIterator first, InputIterator last);*/

	void swap(String&);
	
	void pop_back();

	
	
	//string operator
	const char* c_str()const;

	const char* data()const;

	size_t copy(char* s, size_t len, size_t pos = 0) const;

	size_t find(const String&, size_t pos = 0)const;
	size_t find(const char*, size_t pos = 0)const;
	size_t find(char c, size_t pos = 0)const;
	size_t find(const char* s, size_t pos, size_t n) const;

	size_t rfind(const String& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;
	
	
	size_t find_first_of(const String& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;


	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const String& str, size_t pos = npos) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;


	size_t find_first_not_of(const String& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;


	size_t find_last_not_of(const String& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	String& substr(size_t pos = 0, size_t len = npos) const;

	int compare(const String&) const;
	int compare(const char *) const;
	int compare(size_t pos, size_t len, const String& str)const;
	int compare(size_t pos, size_t len, const string& str,size_t subpos, size_t sublen) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	
	

	

	//operator
	String& operator=(const String& str);
	String& operator=(const char* str);
	String& operator=(char c);
	
	
	

	//Non-member function overloads
	friend istream& operator>>(istream& inDev, String& str);
	friend ostream& operator<< (ostream& outDev, const String& str);
	friend istream& getline(istream& is, String& str, char delim);
	friend istream& getline(istream& is, String& str);

	friend String operator+(const String& left, const String& right);
	friend String operator+(const String& left, const char *right);
	friend String operator+(const char *left, const String& right);
	friend String operator+(const String& left, char right);
	friend String operator+(char left, const String& right);

	friend bool operator<  (const String& lhs, const String& rhs);
	friend bool operator<  (const char*   lhs, const String& rhs);
	friend bool operator<  (const String& lhs, const char*   rhs);
	
	friend bool operator<= (const String& lhs, const String& rhs);
	friend bool operator<= (const char*   lhs, const String& rhs);
	friend bool operator<= (const String& lhs, const char*   rhs);
	
	friend bool operator>  (const String& lhs, const String& rhs);
	friend bool operator>  (const char*   lhs, const String& rhs);
	friend bool operator>  (const String& lhs, const char*   rhs);

	friend bool operator>= (const String& lhs, const String& rhs);
	friend bool operator>= (const char*   lhs, const String& rhs);
	friend bool operator>= (const String& lhs, const char*   rhs);

	friend bool operator==(const String& l, const String& r);
	friend bool operator==(const char* l, const String& r);
	friend bool operator==(const String& l, const char* r);

	friend bool operator!=(const string& l, const string& r);
	friend bool operator!=(const string& l, const char* r);
	friend bool operator!=(const char* l, const string& r);

	friend void swap(String& x, String& y);

	~String();
};



#endif