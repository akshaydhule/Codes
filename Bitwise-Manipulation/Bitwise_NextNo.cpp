/*
//============================================================================
// Name        : Bitwise_NextNo.cpp
// Description : Given a positive integer, print the next smallest and
 * the next largest number that have the same number of 1 bits in their
 * binary representation.
//============================================================================
*/
#include <iostream>
#include <cmath>

using namespace std;

void nextNo(int number)
{
	int ones = 0, len = 0;
	while(number>0)
	{
		len++;
		int val = number & 1;
		if(val == 1)
			ones++;
		number = number >>1;
	}
	int maxno = pow(2, len) - pow(2, len-ones);
	int minno = pow(2, ones) - 1 ;
	cout<<maxno<<" "<<minno<<endl;
}

int main() {
	nextNo(11);
	return 0;
}
