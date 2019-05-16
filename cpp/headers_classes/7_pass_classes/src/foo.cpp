#include <iostream>
#include "foo.h"
#include "subFoo.h"

Foo::Foo()
{
	std::cout << "In Foo Constructor" << std::endl;

	subFooMemberObject = new SubFoo(* this);
}

Foo::~Foo()
{
	delete subFooMemberObject;
}

void Foo::fooFunction()
{
	std::cout << "In Foo Function" << std::endl;
}
