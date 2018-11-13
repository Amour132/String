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
  size_t ret = _size;
  while(pos <= ret)
  {
    _str[ret+len] = _str[ret];
    ret--;
  }
  strncpy(_str+pos,str,len);
  _size += len;
}

void String::Earse(size_t pos,size_t len)
{
  assert(_str);
  size_t ret = len+1;
  size_t tmp = pos;
  while(ret--)
  {
    _str[tmp] = _str[tmp+len];
    tmp++;
  }
  _size -= len;
}

size_t String::Find(char a,size_t pos)
{
  size_t i = 0;
  for(i=pos; i<_size; i++)
  {
    if(_str[i] == a)
    {
      return i;
    }
  }
  return -1;
}

size_t String::Find(char *str,size_t pos)
{
  size_t i = pos;
  for(; i<_size; i++)
  {
    size_t tmp = i;//记录i的位置防止出错，比如aabbbc中找bbc
    char* ret = str;
    while(*ret)
    {
      if(_str[tmp] == *ret)
      {
        ret++;
        tmp++;
      }
      else 
      {
        break;
      }
    }
    if(!(*ret))//如果ret为空说明走到最后找到了
    {
      return i;
    }
  }
  return -1;
}

String& String::operator+=(char a)
{
  if(_size == _capacity)
  {
    Reserve(_capacity*2);
  }
  _str[_size] = a;
  _size++;
  _str[_size] = '\0';
  return *this;
}

String& String::operator+=(char *str)
{
  size_t len = strlen(str);
  if(_size+len > _capacity)
  {
    Reserve(_size+len);
  }
  strcpy(_str+_size,str);
  _size += len;
  return *this;
}

String& String::operator+=(String &s)
{
  size_t len = s.size();
  if(_size+len > _capacity)
  {
    Reserve(_size+len);
  }
  strcpy(_str+_size,s.str());
  _size += len;
  return *this;
}

bool operator==(String &s1,String &s2)
{
  return strcmp(s1._str,s2._str)==0;
}

bool operator!=(String &s1,String &s2)
{
  return !(s1 == s2);
}

bool operator>(String &s1,String &s2)
{
if(strcmp(s1._str,s2._str) > 0) 
{
    return true;
  } 
  return false;
}

bool operator>=(String &s1,String &s2)
{
  return (s1>s2) || (s1 == s2);
}

bool operator<(String &s1,String &s2)
{
  return !(s1 >= s2);
}

bool operator<=(String &s1,String &s2)
{
  return !(s1 > s2);
}

istream& operator>>(istream& is,String &s)
{
  char ch;
  char tmp[1024] = {0};
  size_t i = 0;
  while(is >> ch)
  {
    tmp[i] = ch;
    i++;
  }
  tmp[i] = '\0';
  if(s._str != NULL)
  {
    delete[] s._str;
  }
  s._str = new char[i+1];
  strcpy(s._str,tmp);
  s._size = i;
  return is;
}

ostream& operator<<(ostream &os,String &s)
{
  os<<s._str<<endl;
  return os;
}

