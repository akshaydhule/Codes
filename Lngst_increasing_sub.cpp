//============================================================================
// Name        : Lngst_increasing_sub.cpp
// Description : Find the longest increasing subsequence in partially sorted(Unsorted) array
//============================================================================

#include <iostream>
using namespace std;

int ceilindex(int a[], int min, int high, int val)
{
	while((high-min)>1)
	{
		int mid = min + (high-min)/2;
		if(val>a[mid])
		{
			min = mid;
		}
		else if(val <= a[mid])
			high = mid;
	}
	return high;
}

int printarray(int a[])
{
	int n= sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

int longest_sub(int a[], int n)
{
	int temp[n], count=1;
	temp[0] = a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[0])
		{
			a[0] = a[i];
		}
		else if(a[i]>a[count-1])
		{
			temp[count++] = a[i];
		}
		else
		{
			temp[ceilindex(a,-1, count-1, a[i])] = a[i];
		}
	}
	return count;
}

int main() {
	int a[] = {2,5,3,7,9,13,1};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<longest_sub(a, n);
	return 0;
}
