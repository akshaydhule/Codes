/*
//============================================================================
// Name        : Word_break.cpp
// Description : Given a string s and a dictionary of words dict,
 * determine if s can be segmented into a space-separated sequence
 * of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code"
//============================================================================
*/

#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	if(wordDict.empty()|| s.size()==0)
    		return false;
    	int n = s.size();
    	bool mat[n][n];
    	std::memset(mat,  false, sizeof(mat));
    	for(int i=1;i<=n;i++)
    	{
    		if(wordDict.find(s.substr(0,i))!=wordDict.end())
    			mat[0][i-1] = true;
    	}
    	for(int i=0;i<n;i++)
    	{
    		if(wordDict.find(s.substr(i,1))!=wordDict.end())
    		    mat[i][i] = true;
    	}
    	for(int L = 1;L<=n;L++)
    	{
    		for(int i=0;i<n-L+1;i++)
    		{
    			int j = L+i-1;
    			if(wordDict.find(s.substr(i,L))!=wordDict.end() && (i ==0 || mat[0][i-1] == true))
    			{
    			    mat[i][j] = true;
    			    mat[0][j] = true;
    			}
    		}
    	}
    	if(mat[0][n-2] == true && mat[n-1][n-1] == true)
    		mat[0][n-1] = true;
    	return mat[0][n-1];
    }
};

int main() {
	string s = "abcd";
	unordered_set<string> words;
	words.insert("a");
	words.insert("b");
	words.insert("abc");
	words.insert("cd");
	Solution a;
	if(a.wordBreak(s, words)==true)
		cout<<"true";
	else
		cout<<"false";
	return 0;
}
