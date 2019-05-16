#include <iostream>
#include "TestClass.h"

TestClass::TestClass()
{
  std::cout << "Create TestClass and Handler" << std::endl;
  handler = new EventHandler();
}

void TestClass::ConfigureCallback()
{
  using namespace std::placeholders;

  std::cout << "Set Callback" << std::endl;
  handler->AddHandler(std::bind(&TestClass::Callback, this, _1));
}

void TestClass::Callback(int x)
{
  std::cout << "Passed value is: " << x << std::endl;
}
