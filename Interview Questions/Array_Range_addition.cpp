/*
//============================================================================
// Name        : Array_Range_addition.cpp
// Description : [Leetcode] Range addition :
 * Assume you have an array of length n initialized with all 0's and are given k update operations.
 * Each operation is represented as a triplet: [startIndex, endIndex, inc]
 * which increments each element of subarray A[startIndex ... endIndex]
 * (startIndex and endIndex inclusive) with inc.

 * Return the modified array after all k operations were executed.
//============================================================================
*/
#include <iostream>
#include <vector>
using namespace std;

class range
{
public:
	int start, end, value;
	range(int a, int b, int c):start(a), end(b), value(c){}
};

vector<int> rangeAddition(int size, vector<range> ranges)
{
	vector<int> values(6,0);
	for(int i=0;i<ranges.size();i++)
	{
		values[ranges[i].start] += ranges[i].value;
		if(ranges[i].end<size-1)
			values[ranges[i].end+1] -= ranges[i].value;
	}
	int sum = 0;
	for (int i=0; i<size ; i++)
	{
		sum += values[i];
		values[i] = sum;
	}
	return values;
}

int main()
{
	vector<range> ranges;
	ranges.push_back(range(1,3,2));
	ranges.push_back(range(3,5,3));
	ranges.push_back(range(2,5,1));
	ranges.push_back(range(0,2,-3));
	vector<int> output = rangeAddition(6, ranges);
	for(int i=0;i<output.size();i++)
		cout<<output[i]<<endl;
	return 0;
}
