//============================================================================
// Name        : stringtoURL.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void strtourl(char *s, int length)
{
	int count=0;
	//int length = s->length();
	for(int i=0;i<length;i++)
	{
		if(s[i]==' ')
		{
			count++;
		}
	}
	cout<<count<<"\n";
	int size = length+(2*count) -1;
	int l = size;
	cout<<size<<"\n";
	char *c = (char *) malloc(sizeof(char));

	for( int i=length-1;i>=0;i--)
	{
		cout<<s[i]<<"\n";
		if(s[i]==' ')
		{
			c[size] = '0';
			c[size-1] = '2';
			c[size-2] = '%';
			size = size-3;
		}
		else
		{
			c[size] = s[i];
			size = size-1;
		}
	}
	for( int i=0;i<=l;i++)
	{
		cout<<c[i];
	}
}

int main() {
	string str = "hello world how are you";
	int n = str.length();
	strtourl(&str[0], n);
	return 0;
}
