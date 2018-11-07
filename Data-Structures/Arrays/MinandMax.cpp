//============================================================================
// Name        : MinandMax.cpp
// Description : find min and max element pair in an array
//============================================================================

#include <iostream>
#define INT_MAX 100
using namespace std;

void minandmax (int a[] , int n)
{
	int min=0 , max = INT_MAX;
	int i ;
	if (n<2)
	{
		cout << "no reference";
	}
	if (a[0]>a[1])
	{
		max = a[0];
		min = a[1];
	}
	else
	{
		max = a[1];
		min = a[0];
	}
	for (i=2;i<n;i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
		else if (a[i]<min)
		{
			min = a[i];
		}
	}
	cout << min << " ," << max<< endl;
}
int main() {
	int a[] = {1,2,4,3,2,1,6,8,0};
	int n = sizeof(a)/sizeof(a[0]);
	minandmax(a,n);
	return 0;
}
