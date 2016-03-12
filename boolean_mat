//============================================================================
// Name        : boolmat.cpp
// Description : Generate a boolean matrix
//============================================================================

#include <iostream>
using namespace std;
#define m 4
#define n 4
void boolmat(int a[m][n])
{
	int b[3];
	int c[3];
	int i,j;
	for(i=0;i<m;i++)
	{
		b[i]=0;
	}
	for(i=0;i<n;i++)
		{
			c[i]=0;
		}
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				b[i]=1;
				c[j]=1;
			}
		}
	}
	for (i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(b[i]==1 || c[j]==1)
			{
				a[i][j]=1;
			}
		}
	}
}

void printmat(int a[m][n])
{
	int i,j;
	for (i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cout << a[i][j] << " ";
			}
			cout<<"\n";
		}

}
int main() {
	int a[m][n] = {{1,0,0,1},
					{0,1,0,0},
					{0,0,0,0},
					{0,0,0,0}};
	boolmat(a);
	printmat(a);
	return 0;
}
