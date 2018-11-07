//============================================================================
// Name        : LargestRectangleInHistogram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int LargestRectangle(vector<int> input){
	int max = 0;
	stack<int> indexOrder;
	if(input.size() == 0)
		return 0;
	int i = 0, n = input.size();
	while(i<n){
		if(indexOrder.empty() || input[i]>input[indexOrder.top()]){
			indexOrder.push(i);
			i++;
		}
		else{
			int top = indexOrder.top();
			indexOrder.pop();
			int currentMax = input[top] * (indexOrder.empty() ? i :
																i - indexOrder.top()-1);
			max = (max > currentMax) ? max : currentMax;
		}
	}
	while(!indexOrder.empty()){
		int top = indexOrder.top();
		indexOrder.pop();
		int currentMax = input[top] * (indexOrder.empty() ? i :
															i - indexOrder.top()-1);
		max = (max > currentMax) ? max : currentMax;
	}
	return max;
}

int main() {
	vector<int> input = {6, 2, 5, 4, 5, 1, 6};
	cout<<LargestRectangle(input);
	return 0;
}
