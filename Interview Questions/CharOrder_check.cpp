/*
//============================================================================
// Name        : CharOrder_check.cpp
// Description : Given an input string and ordering string, need to return true
 * if the ordering string is present in Input string.

input = "hello world!"
ordering = "hlo!"
result = FALSE (all Ls are not before all Os)

input = "hello world!"
ordering = "!od"
result = FALSE (the input has '!' coming after 'o' and after 'd',
but the pattern needs it to come before 'o' and 'd')

input = "hello world!"
ordering = "he!"
result = TRUE

input = "aaaabbbcccc"
ordering = "ac"
result = TRUE

//============================================================================
*/
#include <iostream>
#include <map>
using namespace std;

bool charorder(string input, string order)
{
	map<char, int> charord;
	for(int i=0;i<order.size();i++)
	{
		charord.insert(make_pair(order[i], i+1));
	}
	int pos=0;
	for(int i=0;i<input.size();i++)
	{
		if(charord.find(input[i])!= charord.end())
		{
			if(pos>charord[input[i]])
				return false;
			else
				pos = charord[input[i]];
		}
	}
	return true;
}

int main() {
	string input = "aaaabbbbccccc";
	cout<<charorder(input, "ac");
	return 0;
}
