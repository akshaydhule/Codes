//============================================================================
// Name        : Parentheses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<cstdlib>
#include <stack>
#include <string>

bool open(char a)
{
    if(a =='[' || a=='{' || a=='(')
    {
        return 1;
    }
    return 0;
}

bool close(char a)
{
    if(a ==']' || a=='}' || a==')')
    {
        return 1;
    }
    return 0;
}

bool match(char a, char b)
{
    if((a =='[' && b ==']') || (a =='{' && b =='}') || (a =='(' && b ==')'))
    {
        return 1;
    }
    return 0;
}


bool balance(string & s)
{
    stack<char> a;
    for(int i=0;i<s.size();i++)
    {
        if(open(s[i])==1)
        {
            s.push(s[i]);
        }
        if(close(s[i])==1)
        {
            if(!s.empty())
            {
                char b = s.pop();
                if(match(b,s[i])==1)
                {
                    continue;
                }
            }
            else
                return 0;
        }
    }
    return 1;
}

int main()
{
    string s = "{[()]}";
    if(balance(s)==1)
    {
        cout<<"it is";
    }
}
