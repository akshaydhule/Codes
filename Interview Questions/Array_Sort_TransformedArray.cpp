/*
//============================================================================
// Name        : Array_Sort_TransformedArray.cpp
// Description : Given a sorted array of integers nums and
 * integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c
 * to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)
//============================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int functionValue(int i, int a, int b, int c)
{
	return (a*pow(i, 2) + b * i + c);
}

vector<int> tranformedArray(vector <int> values, int a, int b, int c)
{
	vector<int> output(values.size(), 0);
	int i = 0, j = values.size()-1, pos = 0;
	pos = a>0 ? values.size()-1 : 0;
	while(i<=j)
	{
		if(a>=0)
		{
			output[pos--] = functionValue(values[i],a,b,c) >= functionValue(values[j],a,b,c) ?
				functionValue(values[i++],a,b,c) : functionValue(values[j--],a,b,c);
		}
		if(a<0)
		{
			output[pos++] = functionValue(values[i],a,b,c) <= functionValue(values[j],a,b,c) ?
				functionValue(values[i++],a,b,c) : functionValue(values[j--],a,b,c);
		}
	}
	return output;
}

int main() {
	int arr[6] = {-7,-2,-1,1,5,7};
	vector <int> values(&arr[0], &arr[0]+6);
	vector<int> output = tranformedArray(values, -2,2,1);
	for(int i =0;i<output.size();i++)
		cout<<output[i]<<endl;
	return 0;
}
