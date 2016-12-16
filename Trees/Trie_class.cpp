//============================================================================
// Name        : Trie_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
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


int main() {
	 Trie trie;
	 trie.insert("abc");
	 cout<< trie.search("abc");
	 cout<< trie.search("ab");
	 trie.insert("ab");
	 cout<< trie.search("ab");
	 trie.insert("ab");
	 cout<< trie.search("ab");
	return 0;
}
