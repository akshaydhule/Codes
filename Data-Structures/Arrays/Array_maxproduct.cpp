//============================================================================
// Name        : Array_maxproduct.cpp
// Description : Given an array find maximum product
//============================================================================

#include <set>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int MaximumProduct(vector<int> input) {
	if(input.size()<1)
		return 0;
	std::sort(input.begin(), input.end());
	int maxpro =1;
	int i = 0;
	while(i<input.size())
	{
		if(input[i]<0)
		{
			if(maxpro<0)
			{
				maxpro = maxpro * input[i];
				i++;
			}
			else
			{
				if(i<input.size()-1 && input[i+1]<0)
				{
					maxpro = maxpro * input[i] * input[i+1];
					i += 2;
				}
				else
				{
					i++;
				}
			}

		}
		else if(input[i]>0)
		{
			maxpro *= input[i];
			i++;
		}
		else
			i++;
	}
   return maxpro;
}


int main() {
	vector <int > a(4);
	a[0] = 1;
	a[1] = -2;
	a[2] = 3;
	a[3] = -3;
   int b = MaximumProduct(a);
   cout <<b << " ";
   return 0;
}

