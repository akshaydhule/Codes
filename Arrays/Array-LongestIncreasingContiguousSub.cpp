//============================================================================
// Name        : Array-LongestIncreasingContiguousSub.cpp
// Description :
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int LongestSub(vector<int> input)
{
	int length = 1, maxlength = 0;
	for(int i=1; i<input.size(); i++)
	{
		if(input[i]> input[i-1])
			length++;
		else
		{
			maxlength = maxlength>length ? maxlength : length;
			length = 1;
		}
	}
	return maxlength;
}

int main() {
	cout<<LongestSub({2,11,3,5,13,7,19,17,23});
	return 0;
}
