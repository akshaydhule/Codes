//============================================================================
// Name        : zigzag.cpp
// Description : zigzag traversal
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define Pi 3.14
using namespace std;

void zigzag(double mat[][8], int m)
{
	int i = 0, j = 0;
	int it = 1;
	if (m >= 64 || m <= 0)
	{
		return;
	}

	//for upper left triangle of matrix
	do
	{
		j++; it++;
		if (it > m)
			mat[i][j] = 0;
		while (j != 0)
		{
			i++;
			j--; it++;
			if (it > m)
				mat[i][j] = 0;
		}
		i++; it++;
		if (i > 7)
		{
			i--;
			it--;
			break;
		}
		if (it > m)
			mat[i][j] = 0;
		while (i != 0)
		{
			i--;
			j++; it++;
			if (it > m)
				mat[i][j] = 0;
		}
	} while (true);

	//for lower right triangle of matrix
	do
	{
		j++; it++;
		if (it > m)
			mat[i][j] = 0;
		while (j != 7)
		{
			j++;
			i--; it++;
			if (it > m)
				mat[i][j] = 0;
		}
		i++; it++;
		if (i > 7)
		{
			i--; it--;
			break;
		}
		if (it > m)
			mat[i][j] = 0;
		while (i != 7)
		{
			i++;
			j--; it++;
			if (it > m)
				mat[i][j] = 0;
		}
	} while (true);
}
double cval(int c)
{
	if (c == 0)
		return (1.0 / sqrt(2.0));
	else
		return 1.0;
}

void DCT(double **mat, double dct_mat[][8], int xpos, int ypos)
{
	double Cu, Cv, sum = 0.0;
	unsigned int original;
	for (int u = 0; u < 8; u++)
	{
		for (int v = 0; v < 8; v++)
		{
			Cu = cval(u);
			Cv = cval(v);
			sum = 0.0;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					original = mat[x + xpos][y + ypos];
					sum += original * Cu * Cv *
						cos((double)(2 * x + 1) * (double)u * Pi / 16.0)*
						cos((double)(2 * y + 1) * (double)v * Pi / 16.0);
				}
			}
			dct_mat[u][v] = 0.25 * sum;
		}
	}
}
void iDCT(double **mat, double dct_mat[][8], int xpos, int ypos)
{
	double Cu, Cv, sum = 0.0;
	double original = 0.0;
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{

			sum = 0.0;
			for (int u = 0; u < 8; u++)
			{
				for (int v = 0; v < 8; v++)
				{
					Cu = cval(u);
					Cv = cval(v);
					original = dct_mat[u][v];
					sum += 0.25 *original * Cu * Cv *
						cos((double)(2 * x + 1) * (double)u * Pi / 16.0) *
						cos((double)(2 * y + 1) * (double)v * Pi / 16.0);
				}
			}
			if (sum > 255)
				sum = 255;
			if (sum < 0)
				sum = 0;
			mat[x + xpos][y + ypos] = sum;
		}
	}
}

int main() {
	double *mat[8];
	double dct_mat[8][8];
	unsigned int *buf = new unsigned int[64];
	unsigned int *buf1 = new unsigned int[64];
	for(int i=0;i<64;i++)
		buf[i] = i+10;
	for(int i=0;i<8;i++)
		mat[i] = new double[8];
	int it=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{	mat[i][j] = buf[it];
			it++;}

	DCT(mat,dct_mat, 0, 0);

	cout<<"\n";
	for(int i=0;i<8;i++)
	{		for(int j=0;j<8;j++)
			{	cout<<dct_mat[i][j]<<"   ";}
		cout<<"\n";
	}

	zigzag(dct_mat,4);
	cout<<"\n";
	for(int i=0;i<8;i++)
	{		for(int j=0;j<8;j++)
			{	cout<<dct_mat[i][j]<<"   ";}
		cout<<"\n";
	}


	iDCT(mat,dct_mat, 0, 0);
	cout<<"\n";
	for(int i=0;i<8;i++)
			{		for(int j=0;j<8;j++)
					{	cout<<mat[i][j]<<"   ";}
				cout<<"\n";
			}
		cout<<"\n";
		it =0;
		for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
				{	buf1[it] = ( mat[i][j]);
					it++;}

		for (int i=0;i<64;i++)
		{
			cout <<buf1[i]<<" ";
			if(i%8==0)
			{
				cout<<"\n";
			}
		}
	return 0;
}
