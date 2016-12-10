/*
//============================================================================
// Name        : stringchain.cpp
// Description : Given list of strings return maximum length of string such that
 * its substring of every length from 1-n is available in the list
 * Example:
 *  input : [a, ab, abcd, abc]
 *  output: 4
 *  input : [a,b,c,dc,abc]
 *  output: 2
//============================================================================
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


int chainLength(string word, set<string> wordset, map<string, int> wordLength)
{
	if(word.empty() || wordset.find(word) == wordset.end()) {
		return 0;
	}
	int length = 1, newLength = 0;
	for(int i=0; i<word.length(); i++)
	{
		string newWord = word.substr(0, i) + word.substr(i+1);
		int tempLength=0;
		if(wordLength.find(newWord)!=wordLength.end())
			tempLength = wordLength[newWord];
		else
		{
			tempLength = chainLength(newWord,wordset , wordLength);
			wordLength[newWord] = tempLength;
		}
		if(tempLength > newLength) {
			newLength = tempLength;
		}
	}
	return newLength + length;
}


int longestChain(vector<string> words)
{
	if(words.size() == 0)
	{
		return 0;
	}
	set<string> wordset(words.begin(), words.end());
	map<string, int> wordlength;
	int maxLength = -1;
	for(int i=0;i<words.size();i++ ) {
		string str = words[i];
		int length = chainLength(str,wordset, wordlength);
		if(maxLength < length) {
			maxLength = length;
		}
	}
	return maxLength;
}


int main() {
	vector<string> words;
	words.push_back("a");
	words.push_back("b");
	words.push_back("abc");
	words.push_back("cd");
	words.push_back("c");
	words.push_back("sd");
	cout<<longestChain(words);
	return 0;
}
