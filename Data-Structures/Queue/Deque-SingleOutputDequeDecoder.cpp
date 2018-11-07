//============================================================================
// Name        : Deque-SingleOutputDequeDecoder.cpp
// Description : Single output Deque

//============================================================================

#include<iostream>
#include<deque>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

void SingleOutputDequeDecoder(vector<int> input)
{
	int size = input.size();
	vector<int> IndexList(size+1, -1);
	for(int i = 0; i < size; i++)
	{
		IndexList[input[i]] = i;
	}

	deque<int> Deque;
	vector<string> Actions;
	int index = 0;
	for(int i = 1; i < size+1; i++)
	{
		//Empty Deque
		if(Deque.empty())
		{
			Deque.push_back(i);
			Actions.push_back("pushBack");
		}
		else
		{
			//Can pop?
			if(Deque.back() == input[index])
			{
				Deque.pop_back();
				Actions.push_back("popBack");
				index++;
			}

			//if index yet to pop
			if(!Deque.empty())
			{
				if(IndexList[i] > IndexList[Deque.back()])
				{
					Deque.push_front(i);
					Actions.push_back("pushFront");
				}
				else
				{
					Deque.push_back(i);
					Actions.push_back("pushBack");
				}

			}
			else
			{
				Deque.push_back(i);
				Actions.push_back("pushBack");
			}
		}
	}
	while(index<size && !Deque.empty())
	{
		if(Deque.back() == input[index])
		{
			Deque.pop_back();
			Actions.push_back("popBack");
			index++;
		}
		else
		{
			cout<<"impossible";
			return;
		}
	}

	int ActionSize = Actions.size();
	for(int i = 0; i < ActionSize-1; i++)
	{
		cout<<Actions[i]<<",";
	}
	cout<<Actions[ActionSize-1]<<endl;
}

int main() {
	vector<int> input = {4,1,3,2};
	SingleOutputDequeDecoder(input);
	return 0;
}
