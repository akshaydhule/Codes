//============================================================================
// Name        : trailing_zeros.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int trailing_zeros(int n)
{
	int fives =0;
	for (int i=0;i<=n;i++)
	{
		while(i>0)
		{
			if(i%5 == 0)
			{
				fives += 1;
				i = i/5;
			}
			else
				break;
		}
	}
	return fives;
}

int main() {
	cout<<trailing_zeros(10);
	return 0;
}
