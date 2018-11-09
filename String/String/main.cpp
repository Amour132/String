#include <iostream>
#include <string.h>
#pragma warning(disable:4996)

class String
{
public:
	String() :_data(new char[1])
	{
		*_data = '\0';
	}

	String(const char* str) :_data(new char[strlen(str)+1])
	{
		strcpy(_data, str);
	}

	String(String const& s) :_data(new char[strlen(s._data)+1])
	{
		strcpy(_data, s._data);
	}

	~String()
	{
		delete[] _data;
	}

	String operator=(String s)
	{
		this->swap(s);
		return *this;
	}
	
	void swap(String &s)
	{
		std::swap(_data, s._data);
	}

	size_t size()
	{
		return strlen(_data);
	}


private:
	char *_data;
};

int main()
{
	String s1("hello");
	String s2("world");
	String s3;

	s3 = s2;
	return 0;
}