//============================================================================
// Name        : longst_nonrep_substring.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
using namespace std;


int lengthOfLongestSubstring(string s)
{
	unordered_map<char, int> sublen;
	//unordered_map<char, int>::iterator it;
	int start=0,maxlen=1, curlen=1, it;
	if(s.size()<=0)
		return 0;
	sublen.insert(make_pair(s[0], 0));

	for(int i=1;i<s.size();i++)
	{
		if(sublen.find(s[i]) == sublen.end() || i - curlen> sublen.at(s[i]))
		{
			curlen++;
		}
		else
		{
			it = sublen.at(s[i]);
			cout<<it<<"\n";
			maxlen = maxlen>curlen?maxlen:curlen;
			curlen = i - it;
		}
		sublen[s[i]] = i;
	}
	maxlen = maxlen>curlen?maxlen:curlen;
	return maxlen;
}

int main() {
	cout<<lengthOfLongestSubstring("abba");
	return 0;
}
