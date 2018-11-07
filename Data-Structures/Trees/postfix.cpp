//code for opstfx operations
#include <stack>
#include <iostream>
#include <cstdlib>
#include <string>

int solution(string &S) {
    stack<int> a;
    int val,m,n;

    for (unsigned int i=0;i<S.size();i++)
    {
        val = S[i];
        if((val-0)>=0 && (val-0)<=9)
        {
            a.push(val);
        }
        else
        {
            m = a.top();
            a.pop();
            n = a.top();
            a.pop();
            if(val == '+')
            {
                m = m+n;
                a.push(m);
            }
            else
            {
                m = m*n;
                a.push(m);
            }
        }
    }
    if(a.size()>1)
        return -1;
    else
        return a.top();
}

int main()
{
	string s = "asdasda";
	solution(s);
}
