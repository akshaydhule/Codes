//============================================================================
// Name        : Productpuzzle.cpp
// Description :
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

void product (int a[],int n)
{
	int i;
	int *left = (int *)malloc(n*sizeof(int));
	int *right= (int *) malloc (sizeof(int)*n);
	left[0] = 0;
	left [1] = a[0];
	for (i=2;i<n;i++)
	{
		left[i] = left[i-1]*a[i-1];
	}
	right[n-1] = 0;
	right[n-2] = a[n-1];
	for (i=n-3;i>=0;i--)
	{
		right[i] = right[i+1]*a[i+1];
	}
	int b[n];
	cout << (b[0]=right[0]) << " ,";
	for (i=1;i<n-1;i++)
	{
		cout << (b[n]=left[i]*right[i]) << " ,";
	}
	cout << (b[n-1]=left[n-1])<< " ";
	delete[] left;
	delete[] right;
}
int main() {
	int a[]={ 1,2,3,4,3,6,7,9};
	int n = sizeof(a)/sizeof(a[0]);
	product(a,n);
	return 0;
}
