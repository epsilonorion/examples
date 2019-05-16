#include <iostream>
#include "Class.h"

StuffClass::StuffClass()
{
  iVal = 5;
}

StuffClass::~StuffClass()
{
}

void StuffClass::doStuff()
{
  std::cout << "This function will do stuff..." << std::endl << std::endl;

  std::cout << "Such as display global iVal: " << iVal << std::endl << std::endl;
}

void StuffClass::doMoreStuff()
{
  /// Defined global dVal in doMoreStuff function
  dVal = 20.42;

  std::cout << "This function will do more stuff" << std::endl << std::endl;

  std::cout << "Such as display the new global iVal: " << iVal << std::endl;
  std::cout << "And display global dVal: " << dVal << std::endl << std::endl;
}

void StuffClass::doAwesomeStuff()
{
  std::cout << "This function knows how to do stuff, " << std::endl;
  std::cout << "it will have the best stuff." << std::endl;
  std::cout << "It is the best, but there is no better " << std::endl;
  std::cout << "function than this one." << std::endl << std::endl;

  std::cout << "Such as display another new global iVal: " << iVal << std::endl;
  std::cout << "And display a new global dVal: " << dVal << std::endl;
  std::cout << "And display a global string: " << sVal << std::endl;
}
