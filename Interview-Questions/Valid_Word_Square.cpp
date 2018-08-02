/*
//============================================================================
// Name        : Valid_Word_Square.cpp
// Description : Given a sequence of words, check whether it forms a valid
 * word square.

A sequence of words forms a valid word square if the kth row and column
read the exact same string.

Note:

- The number of words given is at least 1 and does not exceed 500.
- Word length will be at least 1 and does not exceed 500.
- Each word contains only lowercase English alphabets
 *
//============================================================================
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool wordSquareCheck(int i, int n, map<string, set<string> > &wordmap,
		vector<vector<char> > &charmat)
{
	if(i == n)
	{
		return (int)charmat.size() == n ? true : false;
	}
	string key = string(charmat[i].begin(), charmat[i].begin()+i);
	set<string>::iterator it;

	for(it = wordmap[key].begin(); it != wordmap[key].end() ; it++)
	{
		string str = *it;
		charmat[i][i] = str[i];
		int j = i + 1;
		for(;j<n;j++)
		{
			charmat[i][j] = str[j];
			charmat[j][i] = str[j];
			if(!wordmap.count(string(charmat[j].begin(),charmat[j].begin()+i+1)))
				return false;
		}
		if(j == n)
			return wordSquareCheck(i+1, n, wordmap, charmat);
	}
	return false;
}

void wordSquare(vector<string> wordblock)
{
	map<string, set<string> > wordmap;
	int s = wordblock[0].size();
	for (int i; i<(int)wordblock.size(); i++)
	{
		if ((int)wordblock[i].size() != s)
			return;
		for(int j =0; j<s; j++)
			wordmap[wordblock[i].substr(0,j)].insert(wordblock[i]);
	}
	vector<vector<char> > charmat(s, vector<char>(s));
	if (wordSquareCheck(0, s, wordmap, charmat) ==true)
		cout<<"it is valid block"<<endl;
	else
		cout<<"it is not a valid block"<<endl;
}

int main() {
	vector<string> wordblock;
	wordblock.push_back("bacd");
	wordblock.push_back("cccd");
	wordblock.push_back("dddd");
	wordblock.push_back("abcc");
	wordSquare(wordblock);
	return 0;
}
