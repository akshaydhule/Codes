//============================================================================
// Name        : test.cpp
// Description : given a string return all palindromic partitions
//============================================================================

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

bool **palin;

void printarray(int start, int end)
{
	cout<<"the array is:";
	for(int i=start;i<end;i++)
	{
		for(int j=start;j<end;j++)
		{
			cout<<palin[i][j]<<" ";
		}
		cout<<"\n";
	}
}
string substring(string s, int i, int j)
{
	string a;
	for(int k=i;k<=j;k++)
		a += s[k];
	return a;
}

void print(stack <string> order)
{
	if(order.empty())
		return;
	string co = order.top();
	if(!order.empty())
	{
		order.pop();
		print(order);
	}
	cout<<" "<<co<<" ";
	order.push(co);
}

void printmat(string s, int l, int r, int n, stack<string> &st)
{
	vector<int> index;
	if(l>r)
	{
		print(st);
		cout<<"\n";
		return;
	}
	if(l<=r)
	{
		for(int j =l;j<=r;j++)
		{
			if(palin[l][j]==true)
			{
				index.push_back(j);
			}
		}
		for(auto it = index.begin();it!=index.end();it++)
		{
			st.push(substring(s, l,*it));
			printmat(s, *it+1, r, n, st);
			st.pop();
		}
	}
}

void substring(string s)
{
	int n = s.size(), maxlen=0, l=0,u=0;
	bool mat[n][n];
	memset(mat, false, sizeof(mat));
	for(int i=0;i<n;i++)
		mat[i][i] = true;
	maxlen = 1;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			mat[i][i+1] = true;
			maxlen = 2;
			l = i;
		}
	}
	for(int L=3;L<=n;L++)
	{
		for (int i=0;i<n-L+1;i++)
		{
			int j = i+L-1;
			mat[i][j] = (mat[i+1][j-1]) && (s[i]==s[j]?true:false);
			if(mat[i][j]==true && L>maxlen)
			{
				maxlen = L;
				l = i;
			}
		}
	}
	palin = new bool *[n];
	for(int i=0;i<n;i++)
		palin[i] = new bool[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			palin[i][j] = mat[i][j];
		}
	}

	stack<string> st;
	printmat( s, 0, n-1, n, st);
}
int main() {
	string s = "aabb";
	substring(s);
	return 0;
}
