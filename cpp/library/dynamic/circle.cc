#include <iostream> 
#include "circle.hh"

using namespace std;

void circle::draw(){
   // simple ascii circle
   cout << "\n";
   cout << "      ****\n";
   cout << "    *      *\n";
   cout << "   *        *\n";
   cout << "   *        *\n";
   cout << "   *        *\n";
   cout << "    *      *\n";
   cout << "      ****\n";
   cout << "\n";
}

extern "C" {
shape *maker(){
   return new circle;
}

class proxy {
public:
   proxy(){
      // register the maker with the factory
      factory["circle"] = maker;
   }
};

// our one instance of the proxy
proxy p;

}
