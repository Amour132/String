#pragma once

#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

class String
{
public:
	//构造函数
	String(const char *str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_str = new char[_size + 1];
		strcpy(_str, str);
	}

	~String()
	{
		delete[] _str;
		_str = NULL;
		_size = _capacity = 0;
	}
	//传统写法
	// String(const String &s)
	// :_str(new char[strlen(s._str)]+1)
	//{
	//strcpy(_str,s._str);
	//}
	//现代写法
	//
	void Swap(String &s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	String(const String &s)
		:_str(NULL)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}

	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}

	char& operator[](size_t pos)
	{
		assert(pos<_size);
		return _str[pos];
	}

	const char& operator[](size_t pos)const
	{
		assert(pos<_size);
		return _str[pos];
	}

	size_t size()const
	{
		return _size;
	}

	size_t capacity()const
	{
		return _capacity;
	}

	char* str()const
	{
		return _str;
	}

  //成员函数
  void Reserve(size_t n);
  void Resize(size_t n,char a = '\0');

  void PushBack(char a);
  void Append(char* str);
  void Insert(size_t pos,char a);
  void Insert(size_t pos,char* str);
  void Earse(size_t pos,size_t len = npos);
  size_t Find(char a,size_t pos = 0);
  size_t Find(char* str,size_t pos = 0);

  String& operator+=(char a);
  String& operator+=(char *str);
  String& operator+=(String &s);
  bool operator<(String& s);
  bool operator==(String& s);


private:
	char* _str;
	size_t _size;
	size_t _capacity;

	static const size_t npos;

};
