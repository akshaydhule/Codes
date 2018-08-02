//============================================================================
// Name        : Array-CalculateBonus.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//Type 1
vector<int> CalculateBonus(vector<int> input){
	vector<int> output(input.size(), 1);

	for(int i = 1; i<input.size(); i++)
	{
		if(input[i]>input[i-1])
			output[i] = output[i-1]+1;
	}

	for(int i = input.size()-2; i >= 0; i--)
	{
		//condition: increasing order but same output
		if(input[i]>input[i+1] && output[i] <= output[i+1])
			output[i] = output[i+1]+1;
	}
	return output;
}

//Type 2
class Employee
{
public:
	int index, value;
	Employee(int v, int i)
	{
		index = i;
		value = v;
	}
};

struct comparator{
bool operator()(Employee a, Employee b){ return a.value>b.value;}
};

vector<int> CalculateBonusHeap(vector<int> input){
	vector<int> output(input.size(), 1);
	priority_queue<Employee, vector<Employee>, comparator> heap;
	for(int i = 0; i<input.size(); i++)
	{
		heap.push(Employee(input[i], i));
	}
	while(!heap.empty())
	{
		Employee temp = heap.top();
		int curr = temp.index;
		if(curr>0){
			//left node
			if(input[curr] > input[curr-1]){
				output[curr] = max(output[curr], output[curr-1] + 1);
			}
		}
		if(curr<input.size()-1){
			//right nodes
			if(input[curr] > input[curr+1]){
				output[curr] = max(output[curr], output[curr+1] + 1);
			}
		}
		heap.pop();
	}
	return output;
}

int main() {
	vector<int> input = {10,3,4,5,2,11,5,3,50,1}, output;
	//input = {2,4,5,3};
	//input = {1,2,3,4,5,6,7,8};
	//input = {8,7,6,5,4,3,2,1};
	output = CalculateBonusHeap(input);
	for(int i=0; i<output.size(); i++)
	{
		cout<<output[i]<<" ";
	}
	return 0;
}
