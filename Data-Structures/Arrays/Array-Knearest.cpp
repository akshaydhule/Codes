//============================================================================
// Name        : Array-Knearest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class dist
{
public:
	int index, value, distance;
	dist(int i, int val, int median){
		index = i;
		value = val;
		distance = abs(median-value);
	}
};

bool comp (int a, int b){ return a<b;}

int getMedian(vector<int> input)
{
	sort(input.begin(), input.end(), comp);
	int middle = input.size()/2;
	if(input.size()%2 == 1)
		return input[middle];
	else
		return (input[middle] + input[middle+1])/2;
}

struct Comparator{bool operator()(dist a, dist b){
	return abs(a.distance) < abs(b.distance);}
};

vector<int> Knearest(vector<int> input, int k){
	int median = getMedian(input);
	priority_queue<dist, vector<dist>, Comparator> MaxHeap;

	for(int i=0; i<k; i++)
		MaxHeap.push(dist(i, input[i], median));

	for(int i = k; i<input.size(); i++)
	{
		if(abs(input[i]-median)<MaxHeap.top().distance)
		{
			MaxHeap.pop();
			MaxHeap.push(dist(i, input[i], median));
		}
	}
	vector<int> output;
	while(!MaxHeap.empty())
	{
		output.push_back(MaxHeap.top().value);
		MaxHeap.pop();
	}
	return output;
}

int main() {
	vector<int> input = {7,14,10,12,2,11,29,3,4}, output;
	output = Knearest(input, 5);
	for(int i = 0; i<output.size(); i++)
		cout<<output[i]<<" ";
	return 0;
}
