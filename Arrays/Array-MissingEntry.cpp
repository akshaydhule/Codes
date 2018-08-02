//============================================================================
// Name        : Array-MissingEntry.cpp
// Description : Missing POsitive Entry
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int MissingEntry(vector<int> input)
{
	int size = input.size();
	int i = 0;
	while(i < size)
	{
		if(input[i] < size && input[i]>0 && input[i] != input[input[i]-1])
		{
			swap(input[i], input[input[i]-1]);
		}
		else
			i++;
	}
	for(int i=0; i<size; i++)
	{
		if(input[i] != i+1 )
			return i+1;
	}
	return INT_MAX;
}

int main() {
	vector<int> input = {3,5,4,-1,5,1,-1};
	cout<<MissingEntry(input);
	return 0;
}
