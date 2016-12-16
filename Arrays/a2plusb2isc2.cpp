//============================================================================
// Name        : a2plusb2isc2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<cmath>
#include <unordered_set>
using namespace std;

int main() {
	int a[] = {3,4,3,5,8,7,9,12,13};
	std::unordered_set<int> square;
	std::unordered_set<int>::iterator it;
	std::unordered_set<int>::iterator it2;
	int n = sizeof(a)/sizeof(a[0]);
	for(int i =0;i<n;i++)
	{
		square.insert(a[i]*a[i]);
	}
	for(it = square.begin(); it!=square.end();it++)
	{
		for(it2 = it; it2!=square.end();++it2)
		{
			if(square.find((*it+*it2))!=square.end())
			{
				cout<<sqrt(*it)<<" "<<sqrt(*it2)<<" "<<sqrt(*it+*it2);
			}
		}
	}
	return 0;
}
