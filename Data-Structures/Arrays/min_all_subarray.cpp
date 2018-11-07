/*
//============================================================================
// Name        : min_all_subarray.cpp
// Description : find min of every subarray of size k in array of n
//============================================================================
*/
#include <iostream>
#include <deque>
using namespace std;

void min_subarray(int a[], int k)
{
	deque<int> ele(k);
	int i=0, n = sizeof(a)/sizeof(a[0]);
	if(n == 0)
		return;
	else
	{
		ele.push_back(0);
	}
	for(i=1;i<k;i++)
	{
		while(!ele.empty() && a[i] < a[ele.back()])
		{
			ele.pop_back();
		}
		ele.push_back(i);
	}
	for(i = k;i<n;i++)
	{
		cout<< a[ele.front()];

		while((!ele.empty()) && ele.front()<(i - k + 1))
			ele.pop_front();

		while((!ele.empty()) && a[i] <= a[ele.back()])
		{
			ele.pop_back();
		}
		ele.push_back(i);
	}
	cout<< a[ele.front()];
}

int main() {
	int a[] = {1,2,4,3,2,5,3};
	min_subarray(a, 3);
	return 0;
}
