#include "String.h"

const size_t String::npos = -1;

void String::Reserve(size_t n)
{
  if(n > _capacity)
  {
    char* newstr = new char[n+1];
    strcpy(newstr,_str);
    delete[] _str;
    _str = newstr;
    _capacity = n;
  }
}

void String::Resize(size_t n,char a)
{
  if(n <= _size)
  {
    _str[n] = '\0';
    _size = n;
  }
  else 
  {
    if(n > _capacity)
    {
      Reserve(n);
    }
    size_t pos = _size;
    while(pos < n)
    {
      _str[pos] = a;
      pos++;
    }
    _str[n] = '\0';
    _size = n;
  }
}

void String::PushBack(char a)
{
  if(_size == _capacity)
  {
    Reserve(_capacity*2);
  }
  _str[_size] = a;
  _size++;
  _str[_size] = '\0';
}

void String::Append(char *str)
{
  if(_size+strlen(str) > _capacity)
  {
    Reserve(_size+strlen(str));
  }
  strcpy(_str+strlen(str),str);
  _size += strlen(str);
}

void String::Insert(size_t pos,char a)
{
  if(_size == _capacity)
  {
    Resize(_capacity*2);
  }
  size_t tmp = pos;
  size_t ret = _size;
  while(pos < ret)
  {
    _str[ret+1] = _str[ret];
    ret--;
  }
  _str[tmp] = a;
  _size++;
}

void String::Insert(size_t pos,char *str)
{
  size_t len = strlen(str);
  if(_size+len > _capacity)
  {
    Reserve(_size+len);
  }


}
