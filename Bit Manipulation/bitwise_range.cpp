//============================================================================
// Name        : bitwiseand_range.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int rangeBitwiseAnd(unsigned long int m,unsigned long int n)
{
	unsigned long int diff = n ^ m;
	int sdiff = log2(diff)+1;
	int val = pow(2, sdiff);
	diff = n - (n%val);
	return diff;
}

int main() {
	cout<<rangeBitwiseAnd(2147483644, 2147483647);
	return 0;
}
