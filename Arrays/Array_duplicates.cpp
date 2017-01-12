//============================================================================
// Name        : Array_duplicates.cpp
// Description : given an array find duplicates
//============================================================================

#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> detect_duplicates(vector<int> input)
{
	map<int, int > valcount;
	map<int, int> :: iterator it;
	for (int i=0;i<input.size();i++)
	{
		if(valcount.find(input[i]) != valcount.end())
			valcount[input[i]] += 1;
		else
			valcount.insert(make_pair(input[i],1));
	}


	vector<int> output;
	for(it = valcount.begin(); it!= valcount.end();it++)
	{
		if(it->second >1)
		output.push_back(it->first);
	}
	return output;
}


int main() {
	vector <int > a;
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
   vector<int> b = detect_duplicates(a);
   for(int i= 0;i<b.size();i++)
   {
	   cout <<b[i]<<endl;
   }
   return 0;
}


