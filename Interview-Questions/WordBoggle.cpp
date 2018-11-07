//============================================================================
// Name        : WordBoggle.cpp
// Description : Word Boggle
// Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character.
// Find all possible words that can be formed by a sequence of adjacent characters.
// Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.
/*
 * Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ
 */
// link : https://practice.geeksforgeeks.org/problems/word-boggle/0
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 7
#define chars 26
typedef struct trienode{
    trienode* lchildren[chars];
    trienode* rchildren[chars];
    bool isend;
}trienode;
trienode* newnode()
{
    trienode* newn = (trienode*)malloc(sizeof(trienode));
    for(int i=0;i<chars;i++)
    {
        newn->lchildren[i] = NULL;
        newn->rchildren[i] = NULL;
    }
    newn->isend = false;
    return newn;
}
void insert(trienode* root,string key)
{
    for(int i=0;i<key.length();i++)
    {
        int index = key[i];
        if(index >= 'A' && index <= 'Z')
        {
            index-='A';
            if(!root->rchildren[index])
                root->rchildren[index] = newnode();
            root = root->rchildren[index];
        }
        else
        {
            index-='a';
            if(!root->lchildren[index])
                root->lchildren[index] = newnode();
            root = root->lchildren[index];
        }
    }
    root->isend = true;
}
bool issafe(int i,int j,bool visited[MAX][MAX],int n,int m)
{
    if(i>=0 && j >=0 && i<n && j <m && !visited[i][j])
        return true;
    return false;
}
unordered_map<string,bool> foundwords;
void search(string s,trienode* root,int i,int j,char mat[MAX][MAX],bool visited[MAX][MAX],int n,int m)
{
    if(root->isend)
    {
        if(foundwords.find(s) == foundwords.end())
            foundwords[s] = true;
    }
    visited[i][j] = true;
    int dir[8][2] = {{1,1},{-1,1},{1,-1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0}};
    for(int k=0;k<chars;k++){
        if(root->lchildren[k])
            {
                char ch = (char)(k+'a');
                for(int p=0;p<8;p++)
                {
                    int nxt_i = i+dir[p][0];
                    int nxt_j = j+dir[p][1];
                    if(issafe(nxt_i,nxt_j,visited,n,m) && mat[nxt_i][nxt_j] == (char)(k+'a'))
                        search(s+ch,root->lchildren[k],nxt_i,nxt_j,mat,visited,n,m);
                }
            }
    }
    for(int k=0;k<chars;k++){
        if(root->rchildren[k])
            {
                char ch = (char)(k+'A');
                for(int p=0;p<8;p++)
                {
                    int nxt_i = i+dir[p][0];
                    int nxt_j = j+dir[p][1];
                    if(issafe(nxt_i,nxt_j,visited,n,m) && mat[nxt_i][nxt_j] == (char)(k+'A'))
                        search(s+ch,root->rchildren[k],nxt_i,nxt_j,mat,visited,n,m);
                }
            }
    }
    visited[i][j] = false;
}
void solve(trienode* root,char mat[MAX][MAX],int n,int m)
{
    foundwords.clear();
    bool visited[MAX][MAX];
    memset(visited,false,sizeof(visited));
    string str;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        int index = mat[i][j];
        if(index >= 'a' && index <= 'z')
        {
            if(root->lchildren[index-'a'])
            {
                str+=mat[i][j];
                search(str,root->lchildren[index-'a'],i,j,mat,visited,n,m);
                str = "";
            }
        }
        else
        {
            if(root->rchildren[index-'A'])
            {
                str+=mat[i][j];
                search(str,root->rchildren[index-'A'],i,j,mat,visited,n,m);
                str = "";
            }
        }
    }
}
bool xsearch(trienode* root,string key)
{
    for(int i=0;i<key.length();i++)
    {
        if(!root->lchildren[key[i]-'a'])
            return false;
        root=root->lchildren[key[i]-'a'];
    }
    return root && root->isend;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int no;
        cin >> no;
        trienode* root = newnode();
        vector<string> dict;
        unordered_map<string,bool> unique_dict_words;
        for(int i=0;i<no;i++)
        {
            string s;
            cin >> s;
            if(unique_dict_words.find(s) == unique_dict_words.end())
            {
                dict.push_back(s);
                insert(root,s);
                unique_dict_words[s] = true;
            }
        }
        sort(dict.begin(),dict.end());
        int n,m;
        cin >> n >> m;
        char boggle[MAX][MAX];
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin >> c;
            boggle[i][j] = c;
        }
        solve(root,boggle,n,m);
        int f=0;
        for(int i=0;i<dict.size();i++)
        {
            if(foundwords.find(dict[i])!=foundwords.end())
            {
                cout << dict[i] << " ";
                f=1;
            }
        }
        if(!f)
            cout << "-1";
        cout << endl;
    }
    return 0;
}
