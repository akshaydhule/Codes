//============================================================================
// Name        : rotatematrix.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Rotate a matrix by 90 degrees
//============================================================================

#include <iostream>
using namespace std;

//two types of iteration

void rotatemat(int a[][4], int m)
{
	int temp;
	for(int i=0;i<m/2;i++)
	{
		for(int j=i;j<m-i-1;j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][m-i-1];
			a[j][m-i-1] = a[m-i-1][m-j-1];
			a[m-i-1][m-j-1] = a[m-j-1][i];
			a[m-j-1][i] = temp;
		}
	}
	for(int i =0 ;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}



void rotatemat1(int a[][4], int m)
{
	int temp;
	for(int i=0;i<m/2;i++)
	{
		for(int j=0;j<m/2;j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][m-i-1];
			a[j][m-i-1] = a[m-i-1][m-j-1];
			a[m-i-1][m-j-1] = a[m-j-1][i];
			a[m-j-1][i] = temp;
		}
	}
	for(int i =0 ;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	int a[][4] ={{1,2,3,4},
			{5,6,7,8},
			{15,16,17,18},
			{51,61,71,81}};
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(a[0])/sizeof(a[0][0]);
	rotatemat(a, m);
	cout<<"\n\n";
	return 0;
}
