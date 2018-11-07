//============================================================================
// Name        : maxdifference.cpp
// Description : max difference b/w two elements such as larger appears later
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
/*
void maxdiff(int a[], int n)
{
	int i;
	int diff=a[1]-a[0];
	int current_sum=diff, max=diff;
	for (i=1;i<n-1;i++)
	{
		diff = a[i+1]-a[i];
		if(current_sum>0)
		{
			current_sum+=diff;
		}
		else
			current_sum = diff;
		if (current_sum>max)
			max = current_sum;
	}
	cout << max;
}
*/
//1st one is memory efficient saving memory of an array
void maxdiff(int a[], int n)
{
	int b[n-1], i;
	int current_sum = a[1]-a[0];
	int max = current_sum;
	for (i=0;i<n-1;i++)
	{
		b[i] = a[i+1]-a[i];
	}
	for (i=1;i<n-1;i++)
	{
		if (current_sum>0)
		{
			current_sum+=b[i];
		}
		else
			current_sum = b[i];
		if (current_sum>max)
			max = current_sum;
	}
	cout << max;
}
int main() {
	int a[] = {4,2,9,6,0,8};
	int n = sizeof(a)/sizeof(a[0]);
	maxdiff(a, n);
	return 0;
}
