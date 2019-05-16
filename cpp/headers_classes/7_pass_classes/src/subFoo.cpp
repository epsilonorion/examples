#include <iostream>
#include "subFoo.h"

Foo::SubFoo::SubFoo(Foo& o)
{
	std::cout << "In SubFoo Constructor" << std::endl;
}

void Foo::SubFoo::subFooFunction()
{
	std::cout << "In SubFoo Function" << std::endl;
}
