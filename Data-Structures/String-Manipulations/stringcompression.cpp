//============================================================================
// Name        : stringcompression.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void compress(string s)
{
	char *a = (char *) malloc(sizeof(char));
	char c,d = s[0];
	int count =1,pointer=0;
	int length = s.length();
	for(int i=1;i<length;i++)
	{
		c = s[i];
		if(c == d)
		{
			count ++;
		}
		else
		{
			a[pointer]= d;
			a[pointer+1] = 48+count;
			pointer = pointer+2;
			count =1;
			d=c;
		}
	}
	a[pointer]= c;
	a[pointer+1] = 48+count;
	pointer = pointer+2;
	for(int i=0;i<pointer;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main() {
	string str = "aaaabbbbcccddd";
	compress(str);
	return 0;
}
