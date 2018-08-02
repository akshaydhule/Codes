/*
//============================================================================
// Name        : water_glass.cpp
// Description : Program to find amount of water in a given glass
	There are some glasses with equal capacity as 1 litre.
	The glasses are kept as follows:

    			   1 --------- 1
		         2   3 ------- 2
		      4    5    6 ---- 3
		    7    8    9   10 - 4
		  11  12   13   14  15 5
	If you have X litre of water and you put that water in top glass,
	how much water will be contained by jth glass in ith row?
//============================================================================
*/
#include <iostream>
using namespace std;

int water_finish(int i)
{
	int count =0;
	for(int k=1;k<i;k++)
	{
		count +=k;
	}
	return count;
}
float water_quantity(int i, int j, float X)
{
	int water_left = X - water_finish(i);
	if(water_left <=0)
		return 0;
	if (i==1)
		return 1;
	else
	{
		if (j == 1 || j == i)
		{
			float water = ((float)water_left/(2*(i-1)));
			return water;
		}
		else
		{
			float water  = ((float)water_left/(i-1));
			return water;
		}
	}
}

int main() {
	float X = 11.0;
	float water = water_quantity(5,2, X);
	cout << "\n water in glass:"<< (float)water;
	return 0;
}
