//============================================================================
// Name        : Array-SmallestNonChange.cpp
// Description : Smallest Nonconstructible change
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp (int a, int b){ return a<b;}

int getChange(vector<int> input)
{
	sort(input.begin(), input.end(), comp);
	int change = 0;
	for(int a : input)
	{
		if(a>change+1)
			return (change+1);
		else
			change += a;
	}
	return change+1;
}

int main() {
	vector<int> input = {12,2,1,15,2,4};
	cout<<getChange(input);
	return 0;
}
