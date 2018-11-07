//============================================================================
// Name        : Deque-SlidingWindowMaximum.cpp
// Description : Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
//============================================================================

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void SlidingWindowMax(vector<int> input, int k)
{
	deque<int> MaxIndexDeque(k);

	//First K elements
	for(int i=0; i<k; i++)
	{
		//remove elements smaller than ith number
		while(!MaxIndexDeque.empty() && input[i] >= input[MaxIndexDeque.back()])
			MaxIndexDeque.pop_back();

		MaxIndexDeque.push_back(i);
	}

	for(int i = k; i<input.size(); i++)
	{
		//print current max
		cout<<input[MaxIndexDeque.front()]<<" ";

		//eliminate out of bound elements
		while(!MaxIndexDeque.empty() && MaxIndexDeque.front() < (i-k+1))
			MaxIndexDeque.pop_front();

		//remove elements smaller than ith number
		while(!MaxIndexDeque.empty() && input[i] >= input[MaxIndexDeque.back()])
			MaxIndexDeque.pop_back();

		MaxIndexDeque.push_back(i);
	}

	//print last max
	cout<<input[MaxIndexDeque.front()]<<" ";
}


int main() {
	vector<int> input = {34, 12,1,78,90,56,89,57};
	SlidingWindowMax(input, 3);
	return 0;
}
