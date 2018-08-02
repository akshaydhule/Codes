//============================================================================
// Name        : Array-ParenthesisCombinations.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void Parentheses(int pos, int n, int open, int close)
{
	static char str[100];

	if(close == n && open == n)
		cout<<str<<endl;
	else
	{
		if(open > close)
		{
			str[pos] = '}';
			Parentheses(pos+1, n, open, close + 1);
		}
		if(open < n)
		{
			str[pos] = '{';
			Parentheses(pos+1, n, open + 1, close);
		}
	}
}

void ParenthesesI(int n, int open, int close, vector<char> *comb)
{
	if(close == n && open == n)
	{
		for(int i = 0; i<comb->size(); i++)
		{
			cout<<comb->at(i);
		}
		cout<<endl;
	}
	else
	{
		if(open > close)
		{
			comb->push_back('}');
			ParenthesesI(n, open, close + 1, comb);
			comb->pop_back();
		}
		if(open < n)
		{
			comb->push_back('{');
			ParenthesesI(n, open + 1, close, comb);
			comb->pop_back();
		}
	}
}

void PrintParentheses(int n)
{
	if(n>0)
		Parentheses(0, n, 0, 0);
	return;
}

void PrintParenthesesI(int n)
{
	vector<char> values;
	if(n>0)
		ParenthesesI(n, 0, 0, &values);
	return;

}

int main() {
	PrintParentheses(3);
	PrintParenthesesI(3);
	return 0;
}
