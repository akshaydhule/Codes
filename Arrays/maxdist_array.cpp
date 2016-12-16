//============================================================================
// Name        : maxdist_array.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int maxdist(int a[],int l, int r)
{
	if(a[l]<a[r])
		return (r-l);
	else
		return max(maxdist(a, l+1, r), max(maxdist(a, l, r-1), maxdist(a, l+1, r-1)));
}


int main() {
	int a[] = {2,5,4,3};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<maxdist(a,0, n-1);
	return 0;
}
