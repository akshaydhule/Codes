//============================================================================
// Name        : RealNo_toString.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

string realtoString(double val)
{
	if(val>1 || val<0)
		return "ERROR";

	string output = ".";
	while(val > 0)
	{
		if (output.size()>32)
			return "ERROR";
		int r = val * 2;
		if(r>=1)
		{
			output += '1';
			val = r -1;
		}
		else
		{
			output += '1';
			val = r;
		}
	}
	return output;
}

int main() {
	cout<<realtoString(0.21);
	return 0;
}
