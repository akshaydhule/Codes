//============================================================================
// Name        : Min_perfectSquares_sumequalto_no.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int perfectsquares(int number)
{
	int *squares = new int[number+1];
	squares[0] = 0;
	squares[1] = 1;
	squares[2] = 2;
	squares[3] = 3;
	int temp =0;
	for(int i = 4 ; i <=number;i++)
	{
		squares[i] = i;
		for(int j=1;j<=i;j++)
		{
			temp = j*j;
			if(temp > i)
				break;
			else
			{
				squares[i] = min(squares[i], 1 + squares[i-temp]);
			}
		}
	}
	delete [] squares;
	return squares[number];
}

vector<int> perfectSquares(int number, int no)
{
	vector<int> consider, skip;
	if(number <4 || no == 1)
	{
		for(int i=0;i<number;i++)
			consider.push_back(1);
		return consider;
	}

	consider = perfectSquares(number - no*no,sqrt(number - no*no));
	skip = perfectSquares(number, no-1);
	if(consider.size()< skip.size())
	{
		consider.push_back(no);
		return consider;
	}
	else
		return skip;
}

int main() {
	int n = 41;
	//cout<<perfectsquares(n);
	vector<int> output = perfectSquares(n, sqrt(n));
	for(int i=0;i<output.size();i++)
		cout<<output[i];
	return 0;
}
