/*
//============================================================================
// Name        : Parantheses_Combination.cpp
// Description :
Each test file starts with an integer ‘t’ - the number of testcases.
In each of the next ‘t’ lines, you are given a string of ‘n’ characters
[ either ‘(‘ or ’)’ or ‘*’ ].
Your task is to find the number of distinct balanced parentheses expressions
you can make by replacing the ‘*’ with either ‘(‘ or ‘)’ or removing the ‘*’
Note : You have to replace each ‘*’ with one of ‘(‘ or ‘)’ or remove it.
If removed, assume the string has reduced by 1 character.
Duplicate strings are not allowed. The final expressions to be counted
have to be distinct
As the answer may be large, please output it modulo 1000000007 (10^9+7)
Output one integer per line corresponding to each testcase.
Constraints :
1 <= t <= 20
1 <= n <= 100
0 <= Number of ‘*’ in the input string <= min(n,10)

Sample Input:

(*(*)*)
*(*(**)*
Sample Output
5
9
Explanation
The six possible valid solutions are for the first input are :
((()))
(()())
(())
(())()
()(())
()()()

//============================================================================
*/

#include <iostream>
#include <set>
#include <stack>

using namespace std;

bool balancedPara(string s)
{
	stack<char> para;
	if(s.size()==0)
		return true;
	para.push(s[0]);
	int i=1;
	while(i<s.size())
	{
		if(s[i] == '(')
			para.push(s[i]);
		else if(s[i] == ')')
		{
			 if(!para.empty())
				 para.pop();
			 else
				 return false;
		}
		i++;
	}

	if(para.empty())
		return true;
	else
		return false;
}

void buildstring(string s, string input ,int pos, int count,set<string> &combs)
{
	if(pos<0)
	{
		if(balancedPara(s) == true)
		{
			combs.insert(s);
		}
		return;
	}
	else
	{

		int end = pos;
		while(input[pos] != '*' && pos>=0)
			pos--;
		int len = end - pos;
		if(count == 0)
		{
			string newS = input.substr(pos+1, len) + s;
			buildstring(newS, input,pos-1, count, combs);
		}
		else
		{
			string newS = input.substr(pos+1, len)+ '(' + s;
			buildstring(newS, input,pos-1, count-1, combs);
			string newS_ = input.substr(pos+1, len)+ ')' + s;
			buildstring(newS_, input,pos-1, count-1, combs);
			string newS__ = input.substr(pos+1, len) + s;
			buildstring(newS__, input,pos-1, count, combs);
		}
	}

}

void stringcombs(string input, set<string> &combs)
{
	int count =0;
	for(int i=0;i<input.size();i++)
	{
		if(input[i] == '*')
			count++;
	}
	string s = "";
	buildstring(s,input,input.size()-1, count,combs);
}

void combinations(string input)
{
	set<string> comb;
	stringcombs(input, comb);
	set<string> ::iterator it;
	for(it = comb.begin();it!= comb.end();it++)
	{
		cout<<*it<<endl;
	}
}

int main() {
	string input = "*(*(**)*";
	combinations(input);
	return 0;
}
