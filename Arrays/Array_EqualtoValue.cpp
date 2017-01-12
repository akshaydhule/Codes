//============================================================================
// Name        : Array_EqualtoValue.cpp
// Description : find if sum of two numbers *100 is equal to value
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;


//complete the function here find if sum of two numbers *100 is equal to value
bool productmatch (vector <int> input, int value)
{
	map<int, int > valcount;

	for (int i=0;i<input.size();i++)
	{
		if(valcount.find(input[i]) != valcount.end())
			valcount[input[i]] += 1;
		else
			valcount.insert(make_pair(input[i],1));
	}

	for (int i=0;i<input.size();i++)
	{
		int value2 =(value/100)-input[i];
		if(valcount.find(value2) != valcount.end())
		{
			if (value2 != input[i])
				return true;
			else if(valcount[value2] >= 2)
					return true;
		}
	}
	return false;
}


int main() {
	vector <int > a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	bool b = productmatch(a, 300);
	cout <<b;
	return 0;

}
