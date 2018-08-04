//============================================================================
// Name        : String-PrintLongestPalindromeSequnce.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
	vector<vector<bool> > status(s.size(), vector<bool>(false));
	string output;
	int Max=0;
	if(s.size() <=1)
		return s;
	for(int i = 0; i<s.size(); i++)
		status[i][i] = true;
	Max=1;
	output = s.substr(0,1);
	for(int i = 0; i<s.size()-1; i++)
	{
		if(s[i] == s[i+1])
		{
			status[i][i+1] = true;
			Max = 2;
			output = s.substr(i,2);
		}
	}
	for(int l = 3; l<=s.size(); l++)
	{
		for(int i = 0; i<s.size()-l+1; i++)
		{
			int j = i+l-1;
			string cur = "";
			if(s[i] == s[j] && status[i+1][j-1] == true)
			{
				status[i][j] = true;
				cur = s.substr(i,l);
			}
			if(Max< cur.size())
			{
				Max = cur.size();
				output = cur;
			}
		}
	}
	return output;
}

int main() {
	string input = "asdaada";
	cout<<longestPalindrome(input);
	return 0;
}
