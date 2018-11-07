//============================================================================
// Name        : Majority.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Find min and second min element in an array
//============================================================================

#include <iostream>
//#include <climits>
#define INT_MAX 1000
using namespace std;

void min(int a[], int n)
{
	int first, second,i;
	first = INT_MAX;
	second = INT_MAX;
	for (i=0;i<n;i++)
	{
		if (a[i]<first)
		{
			second = first;
			first = a[i];
		}
		else if (a[i]<second && a[i]!= first)
		{
			second = a[i];
		}
	}
	cout << first << " ," << second<< endl;
}

int main() {
	int a[] = {1,3,5,7,4,3,5,0,5};
	int n = sizeof(a)/sizeof(a[0]);
	min(a,n);
	return 0;
}
