//============================================================================
// Name        : matspiralprint.cpp
// Description : print the matrix in spiral form
//============================================================================

#include <iostream>
using namespace std;

void print(int a[3][5], int m, int n)
{
	int i, j, k;
	i=0,j=0;
while(i<m && j<n)
{
	for (k=j;k<n;k++)
	{
		cout<<a[i][k]<<" ";
	}
	i++;
	for(k=i;k<m;k++)
	{
		cout<<a[k][n-1]<<" ";
	}
	n--;
	if(i<m)
	{
	for(k=n-1;k>=j;k--)
	{
		cout<<a[m-1][k]<<" ";
	}
	m--;
	}
	if(j<n)
	{
	for (k=m-1;k>=i;k--)
	{
		cout<<a[k][j]<<" ";
	}
	j++;
	}
}
}
int main() {
	int a[3][5] = {{1,2,3,4,5},
				{6,7,8,9,10},
				{11,12,13,14,15}};
	print(a,3,5);
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
