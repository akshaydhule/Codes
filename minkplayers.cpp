//============================================================================
// Name        : minkplayers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void combination(int len, int pos, vector<int> a, int n)
{
	vector<int>::iterator it = a.begin();
	if(len == 0)
	{
		return ;
	}
	else
	{
		for(int i=len;i<=n;i++)
		{
			while(it!=a.end())
			{
				if( (*it%i)!=0 && (i%(*it))!=0 )
				{
					it++;
				}
				else
				{
					break;
				}
			}
			a.insert(i);
			combination(len-1,pos+1,a,n)
		}
	}
}

bool val(int i, int n)
{
	vector<int> a;
	combination(i,0,a,n);
	if (a.size==i)
		return true;
	else
		return false;

}

int main() {
	int n;
	bool k;
	for(int i=2;i<=n;i++)
	{
		 k = val(i,n);
		 if (k==true)
		 {
			 cout<<k;
			 return 0;
		 }
	}
}
