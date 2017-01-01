//============================================================================
// Name        : 1000bulbs.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	bool a[1001];
	for(int i=0;i<=1000;i++)
	{
		a[i]=0;
	}
	for (int i=1;i<=1000;i++)
	{
		for(int j=1;j*i<=1000;j++)
		{
			a[i*j]=!a[i*j];
		}
	}
	int count=0;
	for(int i=1;i<=1000;i++)
	{
		if(a[i]==1)
		{
			count++;
		}

	}
	cout<<count;
	return 0;
}
