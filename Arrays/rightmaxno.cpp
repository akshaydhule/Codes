//============================================================================
// Name        : rightmaxno.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <algorithm>
using namespace std;

int rightgreat(int a[], int l, int h)
{
	int mid=0;
	while(l<=h)
	{
		mid = (h-l)/2 + l;
		return(max(rightgreat(a,l,mid-1),max(a[mid],rightgreat(a,mid+1,h))));
	}
	return 0;
}
int main() {
	int a[] = {1,4,3,2,7,6,0,9,5};
	int n = sizeof(a)/ sizeof (a[0]);
	int b = rightgreat(a,n/2,n);
	cout<<b;
	return 0;
}
