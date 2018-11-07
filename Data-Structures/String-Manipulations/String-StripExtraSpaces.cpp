//============================================================================
// Name        : String-StripExtraSpaces.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

void reverses(string &s, int i, int j)
{
    while(i<j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

void removeSpaces(string &s)
{
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    s.erase(0,s.find_first_not_of(" \n\r\t"));
    int Spaces = 0;
    int i = 0, start = -1;
    cout<<s<<endl;
    while(i<s.size())
    {
        if(s[i] == ' ')
        {
            if(Spaces == 0)
                start = i;
            Spaces+= 1;
        }
        else
        {
            if(start != -1 && Spaces>1)
            {
                s.erase(start+1, Spaces-1);
                i = i - Spaces + 1;
            }
            Spaces = 0;
            start = -1;
        }
        i+= 1;
    }
}

void reverseWords(string &s) {
    if(s.empty())
        return;
    removeSpaces(s);
    int j = s.size()-1;
    int i = 0;
    reverses(s, i, j);
    i = 0;
    for(int j = 1; j<s.size(); j++)
    {
        char c = s[j];
        if(s[j] == ' ')
        {
            reverses(s, i, j-1);
            i = j+1;
        }
    }
    if(i<s.size())
    {
        reverses(s, i, s.size()-1);
    }
}

int main() {
	string input = "c  a  b  d  c  d  c  d  d";
	//reverseWords(input);
	removeSpaces(input);
	cout<<input;
	return 0;
}
