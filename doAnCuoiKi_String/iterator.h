#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include"string.h"
namespace CT{
	class iterator
	{
	private:
		char* current;
	public:


		iterator(char* initLoc = 0) :current(initLoc){}

		iterator& operator++()
		{
			++current;
			return *this;
		}

		iterator operator++(int)
		{
			iterator oldData(*this);
			++current;
			return oldData;
		}

		iterator& operator--()
		{
			--current;
			return *this;
		}

		iterator operator--(int)
		{
			iterator oldData(*this);
			--current;
			return oldData;
		}

		iterator operator+(size_t n)
		{
			iterator oldData(*this);
			current += n;
			return oldData;
		}

		iterator operator=(iterator& rhs)
		{
			*this = rhs;
			return *this;
		}

		bool operator==(const iterator& rhs)const { return current == rhs.current; }

		bool operator!=(const iterator& rhs)const { return current != rhs.current; }

		char& operator*(){ return *current; }

		char* operator->(){ return current; }

	};
	

	class const_iterator
	{
	private:
		char* current;
	public:

		const_iterator(char* initLoc = 0) :current(initLoc){}

		const_iterator& operator++()
		{
			++current;
			return *this;
		}

		const_iterator operator++(int)
		{
			const_iterator oldData(*this);
			++current;
			return oldData;
		}

		const_iterator operator--()
		{
			--current;
			return *this;
		}

		const_iterator operator--(int)
		{
			const_iterator oldData(*this);
			--current;
			return oldData;

		}


		const char& operator*(){ return *current; }

		const char* operator->(){ return current; }

		bool operator==(const const_iterator& rhs)const { return current == rhs.current; }

		bool operator!=(const const_iterator& rhs)const { return current != rhs.current; }

	
	};
	

	class reverse_iterator 
	{
	private:
		char* current;
	public:
		reverse_iterator(char* initLoc = 0) :current(initLoc){}
		
		reverse_iterator& operator++()
		{
			--current;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator oldData(*this);
			--current;
			return oldData;
		}

		reverse_iterator& operator--()
		{
			++current;
			return *this;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator oldData(*this);
			--current;
			return oldData;
		}

		bool operator==(const reverse_iterator& rhs)const { return current == rhs.current; }

		bool operator!=(const reverse_iterator& rhs)const { return current != rhs.current; }

		char& operator*(){ return *current; }

		char* operator->(){ return current; }


	};
	
	class const_reverse_iterator 
	{
	private:
		char* current;
	public:

		const_reverse_iterator(char* initLoc = 0) :current(initLoc){}

		const_reverse_iterator& operator++()
		{
			--current;
			return *this;
		}

		const_reverse_iterator operator++(int)
		{
			const_reverse_iterator oldData(*this);
			--current;
			return oldData;
		}

		const_reverse_iterator operator--()
		{
			++current;
			return *this;
		}

		const_reverse_iterator operator--(int)
		{
			const_reverse_iterator oldData(*this);
			++current;
			return oldData;

		}


		const char& operator*(){ return *current; }

		const char* operator->(){ return current; }

		bool operator==(const const_reverse_iterator& rhs)const { return current == rhs.current; }

		bool operator!=(const const_reverse_iterator& rhs)const { return current != rhs.current; }
	};
};


#endif