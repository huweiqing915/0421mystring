/*************************************************************************
	> File Name: String.h
	> Author: huwq
	> Mail:huweiqing915@gmail.com 
	> Created Time: 2014年04月21日 星期一 22时07分38秒
 ************************************************************************/

#ifndef STRING_H_
#define STRING_H_

#include <string.h>
#include <cstddef>
#include <iostream>

class String {
public:
	String();
	String(const String&);
	String(const char *);
	~String();
	String& operator=(const String&);
	String& operator=(const char*);

	String& operator+=(const String&);
	String& operator+=(const char*);

	char& operator[](std::size_t);
	const char& operator[](std::size_t) const;
	
	std::size_t size() const;
	char* c_str() const;
	void debug();

	friend String operator+(const String&, const String&);
	friend String operator+(const String&, const char*);
	friend String operator+(const char*, const String&);
	
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);

	friend bool operator<(const String&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<=(const String&, const String&);
	friend bool operator>=(const String&, const String&);
	
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);

private:
	char *_str;
};

inline String operator+(const String &lhs, const String &rhs)
{
	String ret(lhs);
	ret += rhs;
	return ret;
}

inline String operator+(const String &lhs, const char *rhs)
{
	return lhs + String(rhs);
}

inline String operator+(const char *lhs, const String &rhs)
{
	return String(lhs) + rhs;
}

inline bool operator==(const String &lhs, const String &rhs)
{
	return strcmp(lhs._str, rhs._str) == 0;
}

inline bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}
inline bool operator<(const String &lhs, const String &rhs)
{
	return strcmp(lhs._str, rhs._str) < 0; 
}

inline bool operator>(const String &lhs, const String &rhs)
{
	return strcmp(lhs._str, rhs._str) > 0;
}

inline bool operator<=(const String &lhs, const String &rhs)
{
	return !(lhs > rhs);
}

inline bool operator>=(const String &lhs, const String &rhs)
{
	return !(lhs < rhs);
}

inline std::ostream& operator<<(std::ostream &os, const String &s)
{
	os << s._str;
	return os;
}

inline std::istream& operator>>(std::istream &is, String &s)
{
	char buf[1024];
	is >> buf;
	if(is)
	{
		s = buf;
	}
	return is;
}

#endif
