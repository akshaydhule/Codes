//============================================================================
// Name        : maxsumsubarray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int maxsumarray(int a[], int n)
{
	int val = 0;
	int temp =0;
	int l=0,h=0,g=0;
	for(int i=0;i<n;i++)
	{
		temp = temp +a[i];
		if(val<temp)
		{
			val = temp;
			h = i;
			l =g;
		}
		if(temp<0)
		{
			g = i+1;
			temp =0;
		}
	}
	cout<<l<<" "<<h;
	return val;
}

int main() {
	int a[] = {-10,1,3,-3,0,9,-7,10,3,-80};
	int n = sizeof(a)/sizeof(a[0]);
	int val = maxsumarray(a, n);
	cout<<val;
	return 0;
}
