#ifndef FOO_H_HEADER
#define FOO_H_HEADER

class Foo
{
public:
	int fooVariable;

	class SubFoo;

	Foo();
	~Foo();
	void fooFunction();

	SubFoo* subFooMemberObject;
};

#endif
