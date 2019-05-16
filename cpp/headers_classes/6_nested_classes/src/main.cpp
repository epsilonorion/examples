#include <iostream>
#include "foo.h"

Foo::Foo()
{
	std::cout << "In Foo Constructor" << std::endl;
}

void Foo::fooFunction() 
{
	std::cout << "In Foo Function" << std::endl;
}

Foo::SubFoo::SubFoo()
{
	std::cout << "In SubFoo Constructor" << std::endl;
}

void Foo::SubFoo::subFooFunction()
{
	std::cout << "In SubFoo Function" << std::endl;
}

int main()
{
	Foo fooObject;
	
	fooObject.fooFunction();

	Foo::SubFoo subFooObject;

	subFooObject.subFooFunction();

	return 0;	
}

