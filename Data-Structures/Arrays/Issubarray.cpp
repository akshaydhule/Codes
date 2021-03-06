//============================================================================
// Name        : Issubarray.cpp
// Description : find if given string is subarray
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
/*
void swap(int *a, int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int l, int h)
{
	int pivot = a[h];
	int i = l-1;
	int j;
	for(j=l;j<=h-1;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[h]);
	return(i+1);
}
void quicksort(int a[], int l, int h)
{
	int p;
	if(l<h)
	{
	p = partition(a,l,h);
	quicksort(a,l,p-1);
	quicksort(a,p+1,h);
	}
}
*/

void merge(int a[], int l, int mid, int h)
{
	int i,j,k=0;
	int n1= (mid-l)+1;
	int n2 = (h-mid);
	int b[n1],c[n2];
	for (i=0;i<n1;i++)
	{
		b[i]=a[i];
	}
	for (j=0;j<n2;j++)
	{
		c[j]=a[mid+j+1];
	}
	i=0;j=0;k=l;
	while (i<n1 && j<n2)
	{
		if(c[j]==b[i])
		{
			a[k]=b[i];
			k++;i++;
			a[k]=c[j];
			k++;j++;
		}
		else if(b[i]<c[j])
		{
			a[k]=b[i];
			k++;
			i++;
		}
		else if (c[j]<b[i])
		{
			a[k]=c[j];
			k++;
			j++;
		}

	}
	while(i<n1)
	{
		a[k]=b[i];
		j++;
		k++;
	}
	while(j<n2)
		{
			a[k]=c[j];
			j++;
			k++;
		}
}
void mergesort(int a[], int l,int h)
{
	if(l<h)
	{
	int mid = (h+l)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,h);
	merge(a,l,mid,h);
	}
}
int sub(int a[],int b[], int n, int m)
{
	int i=0,j=0;
	//quicksort(a,0,n-1);
	//quicksort(b,0,m-1);

	mergesort(a,0,n-1);
	mergesort(b,0,m-1);
	while(i<n && j <m)
	{
		if (b[j]>a[i])
		{
			i++;
		}
		else if(b[j]==a[i])
		{
			i++;
			j++;
		}
		else if(b[j]<a[i])
		{
			return 0;
		}
	}
	if(j<n)
	{
		return 0;
	}
	return 1;
}

int main() {
	int a[]={1,3,4,3,4,7,3};
	int b[]={3,4,3};
	int n = sizeof(a)/sizeof(a[0]);
	int m = sizeof(b)/sizeof(b[0]);
	int temp=sub(a,b,n,m);
	if (temp==0)
	{
		cout<<" it is subarray";
	}
	else
		cout<<"its not a subarray";
	return 0;
}
