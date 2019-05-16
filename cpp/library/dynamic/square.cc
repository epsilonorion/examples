#include <iostream>
#include "square.hh"

void square::draw(){
   // simple ascii square
   std::cout << "\n";
   std::cout << "    *********\n";
   std::cout << "    *       *\n";
   std::cout << "    *       *\n";
   std::cout << "    *       *\n";
   std::cout << "    *       *\n";
   std::cout << "    *********\n";
   std::cout << "\n";
}

extern "C" {
shape *maker(){
   return new square;
}

class proxy { public:
   proxy(){
      // register the maker with the factory
      factory["square"] = maker;
   }
};

// our one instance of the proxy
proxy p;

}
