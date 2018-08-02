//============================================================================
// Name        : Array-RotateArray.cpp
// Description : rotate an array k blocks given extra space of c
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void rotateArray(vector<int> input, int k, int c)
{
	int window = k>c? c : k;
	int iterations = (k%c == 0) ? k/c : k/c+1;
	int size = input.size();
	for(int i=0; i<iterations; i++)
	{
		window = (k%c != 0) && (i == iterations-1) ? k%c : c;
		vector<int> temp(window);
		for(int i=0; i<window; i++)
		{
			temp[i] = input[i];
		}
		for(int j=window; j<size; j++)
		{
			input[j-window] = input[j];
		}
		for(int j=0; j<window; j++)
		{
			input[size-window+j] = temp[j];
		}
	}
	for(int i=0; i<size; i++)
	{
		cout<<input[i]<<" ";
	}
}

int main() {
	rotateArray({1,2,3,4,5,6,7,8,9,10}, 7, 2);
	return 0;
}
