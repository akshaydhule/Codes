#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int a[], int i, int size)
{
	int left, right;
	left = 2*i+1;
	right =2*i+2;
	int smallest = i;
	if(left<size && a[i]>a[left])
	{
		smallest = left;
	}
	if(right<size && a[i]>a[right] && a[left]>a[right])
	{
		smallest = right;
	}
	if(i!=smallest && smallest < size)
	{
		swap(&a[smallest],&a[i] );
		heapify(a,smallest, size);
	}
}

void buildheap(int a[], int size)
{
	for(int i=size/2;i>=0;i--)
	{
		heapify(a,i,size);
	}
}

int main() {
	int a[] = {1,4,3,2,7,6,0,9,5};
	int n = sizeof(a)/ sizeof (a[0]);
	int k = 4;
	int b[] = {1,4,3,2};
	buildheap (b,k);
	for(int i=k;i<n;i++)
	{
		b[0] = a[i];
		buildheap (b,k);
	}
	for (int i=0;i<k;i++)
	{
		cout<< b[i] <<" ";
	}
	return 0;
}
