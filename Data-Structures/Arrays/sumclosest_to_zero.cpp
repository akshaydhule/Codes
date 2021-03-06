//============================================================================
// Name        : strings.cpp
// Description : sum of two elements closest to zero
//============================================================================

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void swap (int *a, int *b);
int partition (int a[], int f,int r);
void quicksort(int *, int f,int r);
void minsum(int a[], int n);

void minsum (int a[], int n)
{
	int min_sum = 1000;
	int min_l=0,min_r=0;
	int l, r,sum;
	l=0;
	r= n-1;
	min_l = l; min_r = n-1;
	quicksort(a,l,r);
	if (r<2)
	{
		cout << "invalid output"<<endl;
		return ;
	}
	sum = a[l]+a[r];
	while(l<r){
	if (abs(sum) < abs(min_sum))
	{
		min_l=l;
		min_r=r;
		min_sum=sum;
	}
	if (sum<0)
	{
		l++;
	}
	else r--;
	}
	cout<< "the sum is min with "<<a[min_l]<< " & "<< a[min_r] << " which is : "<< min_sum <<endl;

}

void quicksort(int a[], int f,int r)
{
	while (f<r)
	{
	int pivot = partition (a,f,r);
	quicksort(a,f,pivot-1);
	quicksort(a,pivot+1,r);
	}
}

void swap (int *a, int *b)
{
	int temp;
	temp = *a;
	*a= *b;
	*b=temp;
}
int partition (int a[], int f,int r)
{
	int pivot = a[r];
	int i=f-1,j;

	for (j=i;j<r-1;j++)
		{
		if (a[j]<pivot)
		{
			swap(&a[i],&a[j]);
			i=i+1;
		}
	}


	swap(&a[i],&a[r]);
	return i+1;
}
int main() {
	int a[] = {12,3,-4,0,-3,2,-10};
	int n = sizeof(a)/sizeof (a[0]);
	minsum(a,n);
	//getchar();
	return 0;
}
