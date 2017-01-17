//============================================================================
// Name        : DWT.cpp
// Description : Implementation of Descrete Wavelet Transform (DWT)
//============================================================================

#include <iostream>
using namespace std;

void FWT(double *buf, int n)
{
	double *temp = new double[n];
	if(n<=1)
		return;
	cout<<" : ";
	int h = n/2;
	for (int i = 0; i < h; i++)
	{
		int k = (i << 1);
		temp[i] = (buf[k]  + buf[k + 1] )/(2);
		temp[i + h] = (buf[k]  - buf[k + 1])/ (2);
		cout<<temp[i]<<" "<<buf[k]<<" "<<buf[k+1]<<" "<<temp[i+h]<<"\n";
	}
	for (int i = 0; i < n; i++)
		buf[i] = temp[i];
}

void   haar_FWT(double **mat)
{

	int rows = 4;
	int cols = 4;

	for (int k = 0; k < 3; k++)
	{
		int l = 1 << k;
		cout<<k;
		int lCols = cols / l;
		int lRows = rows / l;
		cout<<"rows:\n";
		double *row = new double[lCols];
		for (int i = 0; i < lRows; i++)
		{
			cout<<i<<"\n";
			for (int j = 0; j < lCols; j++)
				row[j] = mat[i][j];

			FWT(row,lCols);

			for (int j = 0; j < lCols; j++)
				mat[i][j] = row[j];
		}
		double *col = new double[lRows];
		cout<<"columns:\n";
		for (int j = 0; j < lCols; j++)
		{
			cout<<j<<"\n";
			for (int i = 0; i < lRows; i++)
				col[i] = mat[i][j];

			FWT(col,lRows);

			for (int i = 0; i < lRows; i++)
				mat[i][j] = col[i];
		}
	}
}

void   IWT(double *buf, int n)
{
	double *temp = new double[n];
	if(n<=1)
		return;
	int h = n/2;
	for (int i = 0; i < h; i++)
	{
		int k = (i << 1);
		temp[k] = (buf[i] + buf[i + h] );

		temp[k + 1] = (buf[i] - buf[i + h]);
	}

	for (int i = 0; i < n; i++)
		buf[i] = temp[i];
}

void   haar_IWT(double **mat)
{
	int rows = 4;
	int cols = 4;
	for (int k = 2; k >= 0; k--)
	{
		int l = 1 << k;
		cout<<k;
		int lCols = cols / l;
		int lRows = rows / l;
		double *col = new double[lRows];

		for (int j = 0; j < lCols; j++)
		{

			for (int i = 0; i < lRows; i++)
				col[i] = mat[i][j];

			IWT(col,lRows );

			for (int i = 0; i < lRows; i++)
				mat[i][j] = col[i];
		}


		double *row = new double[lCols];
		for (int i = 0; i < lRows; i++)
		{

			for (int j = 0; j < lCols; j++)
				row[j] = mat[i][j];

			IWT(row,lCols);

			for (int j = 0; j < lCols; j++)
				mat[i][j] = row[j];
		}
	}
}

void D_mat(unsigned int * A, double **B)
{
	int  k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			B[i][j] = A[k]; k++;
		}
	}
}

void reverse_D_mat(double **B, unsigned int * A)
{
	int i = 0;
	for (int j = 0; j < 4; j++)
	{
		for (int k = 0; k < 4; k++)
		{
			A[i] = B[j][k];
			i++;
		}
	}
}

void zigzag(double **mat, int m, int s)
{
	int i = 0, j = 0;
	int it = 1;
	if (m > s*s || m <= 0)
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
		if (i > s-1)
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
		while (j != s-1)
		{
			j++;
			i--; it++;
			if (it > m)
				mat[i][j] = 0;
		}
		i++; it++;
		if (i > s-1)
		{
			i--; it--;
			break;
		}
		if (it > m)
			mat[i][j] = 0;
		while (i != s-1)
		{
			i++;
			j--; it++;
			if (it > m)
				mat[i][j] = 0;
		}
	} while (true);
}

void  DWT_transform(unsigned int *buf, int m)
{
	unsigned int *buf1 = new unsigned int[16];
	double **mat = new double*[4];
	for (int i = 0; i < 4; i++)
		mat[i] = new double[4];

	D_mat(buf, mat);

	haar_FWT(mat);
	zigzag(mat, m,4);
	haar_IWT(mat);
	reverse_D_mat(mat, buf1);
}

int main() {
	unsigned int *buf = new unsigned int[16];
	for(int i=0;i<16;i++)
		buf[i] = i+10;
	DWT_transform(buf,8);


	return 0;
}
