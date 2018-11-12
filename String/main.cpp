#include "String.h"

int main()
{
  String s("hello");
  s.Insert(2,'a');
  cout<<s.str()<<endl;
  return 0;
}
