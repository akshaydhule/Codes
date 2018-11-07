//============================================================================
// Name        : String-stoi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int _stoi(string number)
{
	int output = 0;
	for(int i = 0; i<number.size(); i++)
	{
		int cur = number[i] - '0';
		if(cur<0 || cur>9)
			return -1;
		output = cur*pow(10, number.size()-i-1) + output;
	}
	return output;
}

int main() {
	cout << _stoi("123");
	return 0;
}
