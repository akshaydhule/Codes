/*
//============================================================================
// Name        : Bitwise_swapbits.cpp
// Description : Write a program to swap odd and even bits in an integer
 * with as few instructions as possible (e.g., bit 0 and bit 1 are swapped,
 * bit 2 and bit 3 are swapped, and so on).
 * input : 100110
 * output : 011001
//============================================================================
*/
#include <iostream>

using namespace std;

int swapbits(int number)
{
	int output = 0;
	int first=0, second=0;
	int pos = 0;
	while(number> 0)
	{
		first = number & 1;
		number = number>>1;
		if(number > 0)
		{
			second = number & 1;
			first = (first<<1);
			int temp = (first | second)<<pos;
			output = temp | output;
			pos = pos+2;
			number = number>>1;
		}
		else
			output = (first<<pos) | output;
	}
	return output;
}

int main() {
	cout << swapbits(31);
	return 0;
}
