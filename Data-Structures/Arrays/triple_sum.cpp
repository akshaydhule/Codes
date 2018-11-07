//============================================================================
// Name        : triplesum.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


void merge(int *a, int l, int mid, int r)
{
	int la[mid-l+1];
	int ra[r-mid];
	int i=0;
	int j=0, k=0;
	int ll = (mid-l)+1,lr=(r-mid);
	for(i=l;i<=mid;i++)
		la[j++] =a[i];
	j=0;
	for(;i<=r;i++)
		ra[j++]= a[i];
	i=0;j=0;
	while(i<=ll && j<=lr)
	{
		if(la[i]>ra[j])
		{
			a[k++]= ra[j++];
		}
		else
			a[k++] = la[i++];
	}
	while(i<=ll)
	{
		a[k++] = la[i++];
	}
	while(j<=lr)
	{
		a[k++] = ra[j++];
	}
}

void mergesort(int a[],int l, int r)
{
	while(l<r)
	{
		int mid = l + (r-l)/2;
		mergesort(a, l, mid);
		mergesort(a, mid+1, r);
		merge(a, l, mid, r);
	}
}
bool order(int a, int  b)
{
	return a<b ? true : false;
}

int triplesum(vector<int> a, int value)
{
	//int n = sizeof(a)/sizeof(a[0]);
	int n = a.size();
	std::sort(a.begin(),a.end(), order);
	//mergesort(a, 0, n-1);
	int j=0, k=0;
	int ans =0;
	for(int i=0;i<n-2;i++)
	{
		j = i+1;
		k = n-1;
		while(j<k)
		{
			if((a[i]+a[j]+a[k])>=value)
			{
					k--;
			}
			else
			{
				ans += (k-j);
				j++;
			}
		}
	}
	return ans;
}

int main() {
	vector <int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);
	a.push_back(3);
	cout<<triplesum(a, 7);
	return 0;
}
