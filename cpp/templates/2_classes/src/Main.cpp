#include <iostream>
#include <string>
#include "Stack.h"
#include "Pair.h"
#include "Sequence.h"

using namespace std;

int main(int argc, char * argv[])
{
  try
  {
    cout << "***********************************************" << endl;
    cout << "Show Stack template class" << endl << endl;

    Stack<int> intStack;       // stack of ints
    Stack<string> stringStack; // stack of strings

    // manipulate integer stack
    intStack.push(7);
    cout << intStack.top() << endl;

    // manipulate string stack
    stringStack.push("hello");
    cout << stringStack.top() << std::endl;
    stringStack.pop();
    stringStack.pop();
  }
  catch (exception const &ex)
  {
    cerr << "Exception: " << ex.what() << endl;
//    return -1;
  }

  cout << "***********************************************" << endl;
  cout << "Show Pair template class" << endl << endl;

  Pair<int> intPair (100,75);
  cout << "Int Pair max: " << intPair.getmax() << endl;
  cout << "Int Pair min: " << intPair.getmin() << endl;

  Pair<double> doublePair (42.12, 79.62);
  cout << "Double Pair max: " << doublePair.getmax() << endl;
  cout << "Double Pair min: " << doublePair.getmin() << endl;

  Pair<string> stringPair ("Hello","World");
  cout << "String Pair max: " << stringPair.getmax() << endl;
  cout << "String Pair min: " << stringPair.getmin() << endl;

  cout << "***********************************************" << endl;
  cout << "Show Sequence template class" << endl << endl;

  Sequence <int,5> intSequence;
  intSequence.setmember(0,100);
  cout << "Get Int Sequence Member : " << intSequence.getmember(0) << endl;

  Sequence <double,5> floatSequence;
  floatSequence.setmember (3,3.1416);
  cout << "Get Float Sequence Member : " << floatSequence.getmember(3) << endl;
  return 0;
}
