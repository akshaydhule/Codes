//============================================================================
// Name        : windowsum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector<int> windowsum(vector<int> &values, int size)
{
    vector<int> output;
    if(size == 0 || values.size()<2)
        return output;
    int sum = 0;

    unsigned int s = (unsigned int)size<values.size()?(unsigned int)size:values.size();

    for(unsigned int i=0;i<s;i++)
        sum+= values[i];
    output.push_back(sum);
    for (unsigned int i = s;i<values.size();i++)
    {
        sum -= values[i-s];
        sum += values[i];
        output.push_back(sum);
    }
    return output;
}

int main()
{
    vector<int> values;
    int in = 0;
    int size = 2;
    while(cin>>in)
    {
        values.push_back(in);
        cout<<in;
    }
    vector<int> output;
    //= windowsum(values, size);
    for(unsigned int i=0;i<output.size();i++)
        cout<<output[i];
    return 0;
}
