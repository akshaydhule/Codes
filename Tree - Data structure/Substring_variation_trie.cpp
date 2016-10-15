/*
//============================================================================
// Name        : Substring_variation_trie.cpp
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
#include <vector>
#include <unordered_set>
#include <cstring>
#define Char_size 26
using namespace std;

class TrieNode {
public:
    bool isleaf;
    TrieNode * children[Char_size];
    // Initialize your data structure here.
    TrieNode() {
        isleaf = false;
        for(int i=0;i<Char_size;i++)
            children[i] =  NULL;
    }
    int count ()
    {
        int count =0;
        for(int i =0 ;i<Char_size;i++)
            if(children[i] !=NULL)
                count++;
        return count;
    }
};

int charval(char a)
{
    return int(a)-'a';
}

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *temp = root;
        for(int i=0;i<word.size();i++)
        {
            int ind = charval(word[i]);
            if(!temp->children[ind])
            {
                temp->children[ind] = new TrieNode();
            }
            temp = temp->children[ind];
        }
        temp->isleaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *temp = root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp)
                return false;
            int ind = charval(word[i]);
            if(temp->children[ind] == NULL)
                return false;
            else
            {
                temp = temp->children[ind];
            }
        }
        if(temp->isleaf ==false)
        	return false;
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp)
                return false;
            int ind = charval(prefix[i]);
            if(temp->children[ind] == NULL)
                return false;
            else
            {
                temp = temp->children[ind];
            }
        }
        return true;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	Trie trie;
    	for(auto it = wordDict.begin();it!=wordDict.end();it++)
    	{
    		trie.insert(*it);
    	}
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
    	    	return mat[0][n-1];    }
};


int main() {
	 Trie trie;
	 string s = "leetcode";
	unordered_set<string> words;
	words.insert("leet");
	words.insert("code");
	words.insert("lee");

	 Solution a;
	 	if(a.wordBreak(s, words)==true)
	 		cout<<"true";
	 	else
	 		cout<<"false";

	return 0;
}
