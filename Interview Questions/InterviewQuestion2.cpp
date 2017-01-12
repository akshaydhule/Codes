/*
//============================================================================
// Name        : InterviewQuestion2.cpp
// Description : Given two integer arrays list1 and list2 and an int target value.
 * WAP to check if there exists such a sum, where one number taken from list1
 * and other from list2 to add up to become the target value.
 * Return true if so, else return false.

//============================================================================
*/
#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

bool sumarray(int a[], int b[], int sum)
{
	int len_a = sizeof(a)/sizeof(a[0]);
	int len_b = sizeof(b)/sizeof(b[0]);
	unordered_map<int,int> set;
	unordered_map<int,int>::iterator it;
	for (int i=0;i<len_a;i++)
	{
		set.insert(pair(i, a[i]));
	}
	for(int i=0;i<len_b;i++)
	{
		if(set.find(sum-b[i])!=set.end())
		{
			it = set.find(sum-b[i]);
			cout<< a[*it] << "&"  << b[i];
			return true;
		}
	}
	return false;
}

int main() {
	int a[] = {1,2,4,5,6,7,8};
	int b[] = {2,5,6,3,9};
	sumarray(a, b, 9);
	return 0;
}
