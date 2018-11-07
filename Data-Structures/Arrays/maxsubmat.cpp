//============================================================================
// Name        : maxsubmat.cpp
// Description : square sub-matrix of max size
//============================================================================

#include <iostream>
#include <algorithm>
//#define bool int
#define R 4
#define C 4

using namespace std;

void submat(bool a[R][C])
{
	int s[R][C];
	int i,j,max_value=0, max_row=0,max_col=0;
	for (i=0;i<R;i++)
	{
		s[i][0]=a[i][0];
	}
	for (i=0;i<C;i++)
	{
			s[0][i]=a[0][i];
	}
	for (i=1;i<R;i++)
	{
		for (j=1;j<C;j++)
		{
			if (a[i][j]==1)
			{
				s[i][j] = min(min(s[i][j-1],s[i-1][j]),s[i-1][j-1])+1;
			}
			else
				s[i][j] =0;
		}
	}
	for (i=0;i<R;i++)
	{
		for (j=0;j<C;j++)
		{
			if (s[i][j]>max_value)
			{
				max_value = s[i][j];
				max_row = i;
				max_col = j;
			}
		}
	}
	cout<< "computation matrix: \n";
	for (i=0;i<R;i++)
		{
			for (j=0;j<C;j++)
			{
				cout << s[i][j]<<" ";
			}
			cout << "\n";
		}
	cout << "\n";
	cout <<"output sub-matrix: \n";
	for (i=max_row;i>(max_row-max_value);i--)
	{
		for (j=max_col;j>(max_col-max_value);j--)
		{
			cout << a[i][j]<<" ";
		}
		cout <<"\n";
	}
}
int main() {
	bool a[R][C] = {{1,0,0,0},
				{0,1,1,0},
				{0,1,1,1},
				{1,1,0,0}};
	int i,j;
	cout <<"given matrix: \n";
	for (i=0;i<R;i++)
	{
		for (j=0;j<C;j++)
		{
			cout << a[i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
	submat(a);
	return 0;
}
