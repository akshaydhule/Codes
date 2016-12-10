/*
//============================================================================
// Name        : Palindromic_All_Permutations.cpp
// Description : Given a string s, return all the palindromic permutations
 * ( without duplicates), of it. Return an empty array if no palindromic
 * combinations can be formed.
//============================================================================
*/
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

set<string> palindromicPer(string input)
{
	map<char, int> Charmap;
	set<string> output;
	for(int i=0;i<input.size();i++)
	{
		if(Charmap.find(input[i])!=Charmap.end())
		{
			Charmap[input[i]] += 1;
		}
		else
			Charmap.insert(make_pair(input[i], 1));
	}
	map<char, int> ::iterator charit;
	bool odd=false;
	char oddchar;
	string left = "";
	for(charit= Charmap.begin();charit!=Charmap.end();charit++)
	{
		if(charit->second%2 == 1)
		{
			oddchar = charit->first;
			if(odd == false)
				odd = true;
			else
				return output;
		}
		left += string(charit->second/2, charit->first);
	}

	do
	{
		string palin = left;
		string right = string(palin.rbegin(), palin.rend());
		if(oddchar)
			palin += oddchar;
		output.insert(palin+right);
	}while(next_permutation(left.begin(), left.end()));
	return output;
}

int main() {
	string input = "aaabbcc";
	set<string> output = palindromicPer(input);
	set<string> ::iterator word = output.begin();
	while(word!= output.end())
	{
		cout<<*word<<endl;
		word++;
	}
	return 0;
}
