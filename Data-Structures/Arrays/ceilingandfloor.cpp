//============================================================================
// Name        : ceilingandfloor.cpp

// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : find ceiling and floor of any number in an sorted array
//============================================================================

#include <iostream>
using namespace std;

int search (int a[], int x, int l, int n)
{
	int mid;
	if(l>n)
	{
		return -1;
	}
	if (x == a[l]) return l;
	if ( x == a[n]) return n;

	mid = (l+n)/2;
	if (x == a[mid])
	{
		return mid;
	}
	else if (x > a[mid])
	{
		return search(a,x,mid+1,n);
	}
	else
		return search (a,x,l,mid-1);

}
int main() {
	int a[] = {1,2,3,4,6,7,9,12,14,17,23,25,26,34,37,46,58};
	int x= 46;
	int n = sizeof (a)/sizeof (a[0]);
	int i = search(a,x,0,n);
	if (i==-1 || n==1)
	{
		cout<< "there is no ceiling and floor";
	}
	else if (i==0)
	{
		cout << "No floor "<< " and ceiling: "<<a[i+1];
	}
	else if (i==n-1)
		{
			cout << "floor :"<<a[i-1] <<" No ceiling";
		}
	else
		cout << "floor: "<< a[i-1]<< " and ceiling: "<<a[i+1];
	return 0;
}
