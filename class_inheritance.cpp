//============================================================================
// Name        : Class_implementation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

/*class inheritance : animal to dog & bird
 * Typecasting : dog (Derived) to animal (base)
 * Dynamic casting : with Virtual function
 */
class animal
{
	int legs;
	string type;
	class nested
	{
		int data;
	public:
		void inside()
		{
			cout<<"inside";
		}
	};

public:
	animal(int n, string s):legs(n),type(s)
	{
	}
	void no_of_legs()
	{
		cout<<"in animal class:"<<legs;
	}
	string animal_type() const
	{
		return type;
	}
	static nested f()
	{
		return nested{};
	}
	virtual ~animal() // Polymorphs the B - D structure
	{
	}
};

class dog: public animal
{
	int legs;
	string dogtype;
public:
	dog(int n, string dtype):animal(n,"dog"),legs(n), dogtype(dtype)
	{
	}
	string d_type() const
	{
		return dogtype;
	}
	void no_of_legs()
	{
		cout<<"in dog class:"<<legs;
	}
};

class bird: public animal
{
	string birdtype;
public:
	bird(int n, string btype):animal(n,"bird"), birdtype(btype)
	{
	}
	string d_type() const
	{
		return birdtype;
	}

};

int main() {
	dog d(4, "lab");
	bird b(2, "parrot");
	animal *c = new dog(4, "lab");
	dog * e = (dog *)c;   //D2B type casting
		//or
	dog * f = dynamic_cast<dog *>(c);   //D2B dynamic cast with virtual
		//or
	dog * g = static_cast<dog *>(c);   //D2B static cast
	e->no_of_legs();
	animal::f().inside(); // nested access
	cout<<d.animal_type();
	cout<<b.animal_type();
	return 0;
}
