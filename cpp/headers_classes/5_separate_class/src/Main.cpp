#include <unistd.h>
#include "Class.h"

int main(int argc, char * argv[]) {
  StuffClass stuffClass;

  stuffClass.doStuff();

  // Redefined global iVal in main function after doStuff called
  stuffClass.iVal = 42;

  sleep(2);

  stuffClass.doMoreStuff();

  // Redefined global values
  stuffClass.iVal = 12;
  stuffClass.dVal = 71.1234;
  stuffClass.sVal = "Testing";

  sleep(2);

  stuffClass.doAwesomeStuff();
}
