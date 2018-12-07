#include"string.h"

CT::iterator String::begin()
{
	return CT::iterator(str);
}

const  CT::const_iterator String::begin()const
{
	return str;
}

CT::iterator String::end()
{
	return CT::iterator(str + mLength);
}

const CT::const_iterator String::end()const
{
	return str + mLength;
}

CT::reverse_iterator String::rbegin()
{
	return CT::reverse_iterator(str + mLength - 1);
}

const CT::const_reverse_iterator String::rbegin() const
{
	return str + mLength - 1;
}

CT::reverse_iterator String::rend()
{
	return CT::reverse_iterator(str - 1);
}

const CT::const_reverse_iterator String::rend() const
{
	return str - 1;
}

CT::const_iterator String::cbegin() const noexcept
{
	return str;
}

CT::const_iterator String::cend() const noexcept
{
	return str + mLength;
}

CT::const_reverse_iterator String::crbegin() const noexcept
{
	return str + mLength - 1;
}

CT::const_reverse_iterator String::crend() const noexcept
{
	return str - 1;
}