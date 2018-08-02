/*
//============================================================================
// Name        : Subset_sum_all_inrange.cpp
// Description : Write a function that takes as input
 * an array of integers A, and two integers low and high.
Your function has to output pairs of indices: {(i,j), ...}
Where each pair of indices denotes that the subarray of A[i...j]
has a sum in the range low <= sum <= high.

Apparently there are algorithms better than O(N^2).

//============================================================================
*/
#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > subsetsum(vector<int> numbers, int low, int high)
{
	vector <pair<int, int> > subset;
	vector<int> initialsum(numbers.size(), 0);
	initialsum[0] = numbers[0];
	int size = numbers.size();
	for(int i=1;i<size;i++)
	{
		initialsum[i] = initialsum[i-1] + numbers[i];
	}
	int sum =0;
	for(int i=0;i<size;i++)
	{
		if(numbers[i]>=low && numbers[i]<=high)
		{
			subset.push_back(make_pair(i,i));
		}
	}
	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			sum = initialsum[j] - initialsum[i];
			if(sum>=low && sum <= high)
			{
				subset.push_back(make_pair(i,j));
			}
		}
	}
	return subset;
}

void printsums(vector<pair<int, int> > subsets)
{
	vector<pair<int, int> > ::iterator it;
	for(it=subsets.begin();it!=subsets.end();it++)
	{
		cout<<it->first <<" "<<it->second<<"\n";
	}
}

int main() {
	vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	numbers.push_back(6);
	numbers.push_back(7);
	vector<pair<int, int> > subset = subsetsum(numbers, 4, 20);
	printsums(subset);
	return 0;
}
