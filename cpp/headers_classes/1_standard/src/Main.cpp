#include <iostream>
#include <string>
#include <unistd.h>

/// Global variables for demonstration
int         iVal = 5;
double      dVal;
std::string sVal;

/// Forward declarations of functions
void doStuff();
void doMoreStuff();
void doAwesomeStuff();

int main(int argc, char * argv[]) 
{
  doStuff();

  // Redefined global iVal in main function after doStuff called
  iVal = 42;

  sleep(2);

  doMoreStuff();

  // Redefined global values
  iVal = 12;
  dVal = 71.1234;
  sVal = "Testing";

  sleep(2);

  doAwesomeStuff();

  return 0;
}

void doStuff()
{
  std::cout << "This function will do stuff..." << std::endl << std::endl;

  if (iVal == 12)
  {
    std::cout << "Value was 12" << std::endl;
  }
  else
  {
    std::cout << "Value was not 12" << std::endl;
  }
  

  std::cout << "Such as display global iVal: " << iVal << std::endl << std::endl;
}

void doMoreStuff()
{
  /// Defined global dVal in doMoreStuff function
  dVal = 20.42;

  for (int i = 0; i < 5; i++)
  {
    std::cout << "DVal is equal to: " << dVal + i << std::endl;
  }

  std::cout << "Dval is currently equal to: " << dVal << std::endl;

  std::cout << "This function will do more stuff" << std::endl << std::endl;

  std::cout << "Such as display the new global iVal: " << iVal << std::endl;
  std::cout << "And display global dVal: " << dVal << std::endl << std::endl;
}

void doAwesomeStuff()
{
  int j = 5;
  while (j > 0)
  {
    dVal = dVal - j;
    std::cout << "Dval is now: " << dVal << std::endl;
    j--;
  }

  std::cout << "This function knows how to do stuff, " << std::endl;
  std::cout << "it will have the best stuff." << std::endl;
  std::cout << "It is the best, but there is no better " << std::endl;
  std::cout << "function than this one." << std::endl << std::endl;

  std::cout << "Such as display another new global iVal: " << iVal << std::endl;
  std::cout << "And display a new global dVal: " << dVal << std::endl;
  std::cout << "And display a global string: " << sVal << std::endl;
}
