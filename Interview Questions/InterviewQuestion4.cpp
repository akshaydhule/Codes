/*
//============================================================================
// Name        : GoogleQ4.cpp
// Description : Given two object arrays of "id,weight" (sorted by weight),
 * merge them together and create a one single array.
 * If the "id"s are same values should be merged.
 * Final resulting array should be sorted by weight.
 * Result should be O(nlogn) in time complexity.

//============================================================================
*/


#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;


class idpair
{
	int id;
	int value;
	public:
	void setvalues(int a, int b)
	{
		id = a;
		value = b;
	}
};

bool comparevalue(idpair a, idpair b)
{
	return a.value - b.value;
}

bool compareid(idpair a, idpair b)
{
	return a.id - b.id;
}

int main() {
	int n =2, m = 3;
	idpair a[2];
	idpair b[3];
	a[0].setvalues(1,2);
	a[1].setvalues(2,4);
	b[0].setvalues(2,1);
	b[1].setvalues(3,2);
	b[2].setvalues(1,4);
	std::sort(a,a+n, compareid);
	idpair c[m+n];
	for(int i=0;i<n;i++)
		c[i] = a[i];
	int j=0;
	for(int i=0;i<m;i++)
		c[i] = a[n+i];
	std::sort(c,c+m+n, compareid);
	for(int i=0;i<m+m;i++)
	{
		if(c[j] == c[i])
			c[j].value += c[i].value;
		else
		{
			j++;
			c[j] = c[i];
		}
	}

	return 0;
}
