//============================================================================
// Name        : String-LongestValidParantheses.cpp
// Description : '((())()(()('
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

int GetLongestParantheses(string input)
{
	stack<int> LeftParantheses;
	int end = -1;
	int maxLength = 0;
	for(int i=0; i<input.size(); i++)
	{
		if(input[i] == '(')
			LeftParantheses.push(i);
		else if(LeftParantheses.empty())
			end = i;
		else
		{
			LeftParantheses.pop();
			int start = LeftParantheses.empty() ? end : LeftParantheses.top();
			maxLength = max(maxLength, i - start);
		}
	}
	return maxLength;
}

int main() {
	string input = "((())())(()(";
	cout<<GetLongestParantheses(input);
	return 0;
}
