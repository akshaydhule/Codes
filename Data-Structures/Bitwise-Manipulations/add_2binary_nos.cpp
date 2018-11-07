//============================================================================
// Name        : add_2binary_nos.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

string addnos(string a, string b)
{
	int i = a.size()-1, j = b.size()-1;
	int k = i>=j? i+1:j+1;
	string con(abs(i-j),'0');
	if(i>j)	b = con+b;
	if(j>i)	a = con+a;
	std::string output(k+1,'\0');
	i = k-1;
	j = k-1;
	int carry = 0;
	while(i>=0 && j>= 0)
	{
		if(a[i] == '0' && b[j] == '0')
		{
			if(carry == 0) output[k] = '0';
			if(carry == 1)
			{
				output[k] = '1';
				carry = 0;
			}
		}
		else if((a[i] == '0' && b[j] == '1') ||
				(a[i] == '1' && b[j] == '0'))
		{
			if(carry == 1) output[k] = '0';
			if(carry ==0)
				output[k] = '1';
		}
		else if(a[i] == '1' && b[j] == '1')
		{
			if(carry == 1)
				output[k] = '1';
			if(carry ==0)
			{
				output[k] = '0';
				carry =1;
			}
		}
		k--;
		i--;
		j--;
	}
	if(carry == 0)
		output[k] = '0';
	else
		output[k] = '1';
	return output;
}

int main() {
	string a = "11";
	string b = "1111";
	string c = addnos(a, b);
	cout<<c;
	return 0;
}
