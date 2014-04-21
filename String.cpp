/*************************************************************************
	> File Name: String.cpp
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月21日 星期一 22时13分57秒
 ************************************************************************/

#include "String.h"

String::String():_str(new char[1]) 
{
	_str[0] = '\0';
}

String::String(const char *s)
{
	_str = new char[strlen(s) + 1];
	strcpy(_str, s);
}


String::String(const String &s)
{
	_str = new char[s.size() + 1];
	strcpy(_str, s._str);
}


String::~String()
{
	delete[] _str;
	_str = NULL;
//	std::cout << "destruct" << std::endl;
}

String& String::operator=(const String &s)
{
	if(s != *this)
	{
		delete[] _str;
		_str = NULL;
		_str = new char[s.size() + 1];
		strcpy(_str, s._str);
	}
	return *this;
}

String& String::operator=(const char *s)
{
	delete[] _str;
	_str = NULL;
	_str = new char[strlen(s) + 1];
	strcpy(_str, s);
	return *this;
}

String& String::operator+=(const String &s)
{
	char *tmp = new char[size() + s.size() + 1];
	strcpy(tmp, _str);
	strcat(tmp, s._str);

	delete[] _str;
	_str = NULL;
	_str = tmp;
	return *this;
}

String& String::operator+=(const char *s)
{
	*this += String(s);
	return *this;
}

char* String::c_str() const
{
	return _str;
}

std::size_t String::size() const
{
	return strlen(_str);
}

char& String::operator[](std::size_t index)
{
	return _str[index];
}

const char& String::operator[](std::size_t index) const
{
	return _str[index];
}

void String::debug()
{
	std::cout << _str << std::endl;
}

