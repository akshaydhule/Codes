//============================================================================
// Name        : Majority.cpp
// Description : Find majority element in sorted array i.e. with occurance more than n/2
//============================================================================

#include <iostream>
using namespace std;

bool majority (int a[], int n, int b)
{
	int i=0;
	int last_index = n%2 ? (n/2+1) : (n/2 );
	for (i=0;i<=last_index;i++)
	{
		if (a[i]==b && a[last_index]==b)
		{
			return 1;
		}
	}
	return 0;
}

int main() {
	int a[] = {1,2,2,3,3,3,3,3,3,4,5};
	int n = sizeof (a)/sizeof(a[0]);
	int b=3;
	if (majority (a,n,b))
	{
		cout <<"true";
	}

	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
