//============================================================================
// Name        : zeromatrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;


/*
void zeromatrix(int a[][4])
{
	bool b[4],c[4];
	for(int i=0;i<4;i++)
	{
		b[i] = true;
		c[i]= true;
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0)
			{
				b[i] = false;
				c[j] = false;
			}
		}
	}
	for(int i =0;i<4;i++)
	{
		if(b[i]==false)
		{
			for(int j=0;j<4;j++)
			{
				a[i][j] = 0;

			}
		}
		if(c[i]==false)
				{
					for(int j=0;j<4;j++)
					{

						a[j][i] =0;
					}
				}
	}
	for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
}
*/
//vector

void zeromatrix(int a[][4])
{
	vector<int> b;
	vector<int> c;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(a[i][j]==0)
			{
				b.push_back(i);
				c.push_back(j);
			}
		}
	}
	while(!b.empty())
	{
		int r = b.back();
		b.pop_back();
		for(int i=0;i<4;i++)
		{
			a[r][i] = 0;
		}
	}
	while(!c.empty())
		{
			int col = c.back();
			c.pop_back();
			for(int i=0;i<4;i++)
			{
				a[i][col] = 0;
			}
		}

	for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
}


int main() {
	int a[][4] ={{1,1,0,1},
				{1,0,1,1,},
				{1,1,1,1},
				{1,1,1,1}};
	zeromatrix(a);
	return 0;
}
