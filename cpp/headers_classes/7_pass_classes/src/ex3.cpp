#include <iostream>
#include "foo.h"
#include "subFoo.h"

int main()
{
	// Create foo object. Will Call foo constructor, then subFoo constructor.
	Foo fooObject;	

	// Call simple fooFunction within foo object
	fooObject.fooFunction();

	// Call simple subFooFunction within member of the fooObject object. Was created when fooObject was created.
	fooObject.subFooMemberObject->subFooFunction();
	
	// Create subFoo object. Will call subFoo constructor.
	Foo::SubFoo subFooObject(fooObject);

	// Call simple subFooFunction within subFoo object
	subFooObject.subFooFunction();

//	fooObject.subFooMemberObject = new SubFoo(*this);	

	return 0;	
}

