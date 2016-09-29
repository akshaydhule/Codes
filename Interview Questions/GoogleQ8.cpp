/*
//============================================================================
// Name        : GoogleQ8.cpp
// Description : Find the largest and smallest number in a list.
 * The list is stored as two sections, one in ascending order
 * and the other in descending order.

input [ 2 3 4 5 6 7 10 9 8 7]
smallest : 2
Largest 10

//============================================================================
*/
#include <iostream>
#include <climits>

using namespace std;


void minmax(int a[], int n)
{
	int min = INT_MAX, max = INT_MIN;
	if(n==1)
	{
		cout<<"Only One element in list: "<<a[0];
		return;
	}
	if(n==2)
	{
		min = a[0]>a[n-1] ? a[n-1] : a[0];
		max = a[0]<a[n-1] ? a[n-1] : a[0];
		cout<<"Min value is"<<min;
		cout<<"Max value is"<<max;
		return;
	}
	min = a[0]>a[n-1] ? a[n-1] : a[0];
	cout<<"\nMin value is: "<<min;
	int l=0,r=n-1;
	int mid = INT_MAX;
	while(l<r)
	{
		mid = l + (r-l)/2;
		if(a[mid]>a[mid-1])
		{
			l = mid;
		}
		if(a[mid]>a[mid+1])
		{
			r = mid;
		}
	}
	cout<<"\nMax value is: "<<a[mid];
	return;
}

int main() {
	int a[] = {1,2,3,4,5,6,7,8,7,4};
	int n = sizeof(a)/sizeof(a[0]);
	minmax(a,n);
	return 0;
}
