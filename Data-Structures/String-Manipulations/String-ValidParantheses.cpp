//============================================================================
// Name        : String-ValidParantheses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <stack>
using namespace std;

bool isValid(string s) {
    map<char, char> paramap;
    stack<char> para;
    int i = 0;
    if(s.size()%2== 1)
        return false;
    paramap.insert(make_pair(')','('));
    paramap.insert(make_pair('}','{'));
    paramap.insert(make_pair(']','['));
    while(i<s.size())
    {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
            para.push(s[i]);
        else if(para.empty() == true || paramap[s[i]] != para.top())
            return false;
        else if(s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if(para.empty()== false && paramap[s[i]] == para.top())
                para.pop();
            else
                return false;
        }
        i++;
    }
    if(para.empty())
        return true;
    return false;
}

int main() {
	cout<<isValid("){");
	return 0;
}
