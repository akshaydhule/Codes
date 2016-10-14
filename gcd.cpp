//============================================================================
// Name        : gcd.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int gcd (int a, int b)
{
	int temp = b%a;
	if(temp==0)
		return a;
	return gcd(temp,a);
}
int main() {
	cout<<gcd(210,45);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
