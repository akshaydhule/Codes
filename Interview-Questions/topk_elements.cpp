/*
//============================================================================
// Name        : topk_elements.cpp
// Description : Given an array of numbers
 * return top (Max) K Elements
//============================================================================
*/
#include <iostream>
#include <vector>
using namespace std;


class heap
{
public:
	vector<int> a;
	 int n;
	heap( int n)
	{
		this->n = n;
		this->a.reserve(n);
	}
	void swap(int i, int j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	void addval(vector<int> val)
	{
		int size = n>val.size()?val.size():n;
		for( int i=0;i<size;i++)
			a.push_back(val[i]);

	}
	void heapify( int i)
	{
		int min_ind=i, j = (2*i)+1;
		if(i>=n)
			return;
		if(i<n)
		{
			if(a[i]>a[j] && j<n)
			{
				min_ind = j;
			}
			if(a[min_ind]>a[j+1] && j+1 < n)
			{
				min_ind = j+1;
			}
			if(min_ind != i && min_ind<n)
			{
				swap(i, min_ind);
				heapify(min_ind);
			}
		}
	}
	void buildheap()
	{
		for(int i=(n/2)-1;i>=0;i--)
		{
			heapify(i);
		}
	}
	void print ()
	{
		for ( int i=0;i<a.size();i++)
			cout<<" " << a[i];
	}
	void topkelements(vector<int> val)
	{
		if(a.size()!= n)
		{
			print();
			return;
		}
		else
		{
			for(  int i= n;i<val.size();i++)
			{
				if(a[0]<val[i])
				{
					a[0] = val[i];
					heapify(0);
				}
			}
		}
		print();
	}
};


int main() {
	heap maxheap(5);
	vector<int> val;
	val.push_back(0);
	val.push_back(3);
	val.push_back(2);
	val.push_back(6);
	val.push_back(8);
	val.push_back(1);
	val.push_back(9);
	val.push_back(5);
	maxheap.addval(val);
	maxheap.buildheap();
	//maxheap.print();
	maxheap.topkelements(val);
	return 0;
}
