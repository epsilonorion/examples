#include <iostream>
#include "TestClass.h"

int main(int argc, char * argv[])
{
  std::cout << "Create and use testclass" << std::endl;

//  TestClass *testing;
//  testing = new TestClass();
  TestClass testing;
  testing.ConfigureCallback();

  while (true)
  {

  }

  std::cout << "Finished" << std::endl;

  return 0;
}
