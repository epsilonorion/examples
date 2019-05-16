#ifndef SUBFOO_H_HEADER
#define SUBFOO_H_HEADER

#include "foo.h"

class Foo::SubFoo
{
public:
    int subFooVariable;

	SubFoo(Foo& o);

	void subFooFunction();
};

#endif
