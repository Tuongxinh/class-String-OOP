#ifndef __STRING_H__
#define __STRING_H__
#include <algorithm>
#include<limits>
#include<iostream>
#include<cmath>
#include<string.h>
#include<iterator>
#include<iomanip>
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
	//constructor
	String();
	String(const char*);
	String(const char*, size_t num);
	String(const String&, size_t pos = 0, size_t num = npos);
	String(size_t, char c = 0);

	//capacity
	size_t length()const;
	size_t size();
	size_t capacity()const;
	void clear();
	bool empty();
	void resize(size_t n);
	void resize(size_t n, char c);
	void reserve(size_t newSize = 0);
	void shrink_to_fit();

	
	size_t max_size() const;


	//Iterators

	class iterator
	{
	protected:
		char* current;
	public:
		

		iterator(char* initLoc=0) :current(initLoc){}

		iterator& operator++()
		{
			++current;
			return *this;
		}

		iterator operator++(int unused)
		{
			iterator oldData(*this);
			++current;
			return oldData;
		}

		bool operator==(const iterator& rhs)const { return current == rhs.current; }
		
		bool operator!=(const iterator& rhs)const { return current != rhs.current; }
		
		char& operator*(){ return *current; }

		char* operator->(){ return current; }


		
		~iterator(){ delete current; }
	};
	//
	class const_iterator
	{
	protected:
		char* current;
	public:
	

		const_iterator(char* initLoc=0) :current(initLoc){}

		const_iterator operator++()
		{
			++current;
			return *this;
		}

		const_iterator operator++(int unused)
		{
			const_iterator oldData(*this);
			++current;
			return oldData;
		}

		const char& operator*(){ return *current; }

		const char* operator->(){ return current; }

		bool operator==(const const_iterator& rhs)const { return current == rhs.current; }

		bool operator!=(const const_iterator& rhs)const { return current != rhs.current; }

		~const_iterator(){ delete current; }
	};
	//
	class reverse_iterator:public iterator
	{
	public:
		//reverse_iterator() :iterator(){};

		reverse_iterator(char* initLoc=0) :iterator(initLoc){}
	};
	//
	class const_reverse_iterator :public const_iterator
	{
	public:
		//const_reverse_iterator() :const_iterator(){}

		const_reverse_iterator(char* initLoc=0) :const_iterator(initLoc){}
	};

	iterator begin();
	const const_iterator begin()const;

	iterator end();
	const const_iterator end()const;

	reverse_iterator rbegin();
	const const_reverse_iterator rbegin() const;

	reverse_iterator rend();
	const const_reverse_iterator rend() const;

	/*const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;
	const_reverse_iterator crbegin() const noexcept;
	const_reverse_iterator crend() const noexcept;*/

	//string operator
	size_t find(const String&, size_t pos = 0)const;
	size_t find(const char*, size_t pos = 0)const;
	size_t find(char c, size_t pos = 0)const;
	size_t find(const char* s, size_t pos, size_t n) const;

	size_t copy(char* s, size_t len, size_t pos = 0) const;

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


	int compare(const String&) const;
	int compare(const char *) const;

	String& substr(size_t pos = 0, size_t len = npos) const;
	char* c_str();
	char* data();

	//Modifiers:
	String& erase(size_t pos = 0, size_t n = npos);
	void swap(String&);
	void push_back(const char c);
	void pop_back();

	String& append(const String& str);
	String& append(const char* s);
	String& append(const char* s, size_t num);
	String& append(const String& str, size_t subpos, size_t sublen);
	String& append(size_t num, char c);

	String& assign(const String& str);
	String& assign(const String& str, size_t subpos, size_t sublen);
	String& assign(const char* s);
	String& assign(const char* s, size_t n);
	String& assign(size_t n, char c);
	
	String& INSERT(size_t pos, const char* s);
	String& insert(size_t pos, const String& str);
	String& insert(size_t pos, const String& str, size_t subpos, size_t sublen);
	String& insert(size_t pos, const char* s);
	String& insert(size_t pos, const char* s, size_t n);
	String& insert(size_t pos, size_t n, char c);

	String& replace(size_t pos, size_t len, const String& str);
	//String& replace(iterator i1, iterator i2, const String& str);
	String& replace(size_t pos, size_t len, const String& str,	size_t subpos, size_t sublen);
	String& replace(size_t pos, size_t len, const char* s);
	//String& replace(iterator i1, iterator i2, const char* s);
	String& replace(size_t pos, size_t len, const char* s, size_t n);
	//String& replace(iterator i1, iterator i2, const char* s, size_t n);
	String& replace(size_t pos, size_t len, size_t n, char c);
	//String& replace(iterator i1, iterator i2, size_t n, char c);
	/*template <class InputIterator>
	string& replace(iterator i1, iterator i2,InputIterator first, InputIterator last);*/

	//element access
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;

	//operator
	String& operator=(const String& str);
	String& operator=(const char* str);
	String& operator=(char c);
	
	String& operator+= (const String& str);
	String& operator+= (const char* s);
	String& operator+= (const char c);

	const char& operator[](const size_t pos) const;
	char& operator[](const size_t pos);

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