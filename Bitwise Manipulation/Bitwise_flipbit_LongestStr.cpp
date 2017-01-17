/*
//============================================================================
// Name        : Bitwise_flipbit_LongestStr.cpp
// Description : You have an integer and you can flip exactly one bit from a 0 to a 1.
 * Write code to find the length of the longest sequence of ls you could create.
 * EXAMPLE Input: 1775
 * Output: 8 (or: 11011101111)
//============================================================================
*/
#include <iostream>
#include <map>

using namespace std;

int longeststr(int number)
{
	map<int, int> poslen;
	int len = 0, pos = 0;
	while(number>0)
	{
		int val = number & 1;
		if (val == 1)
		{
			len ++;
		}
		else if(val == 0)
		{
			if (len != 0)
			{
				poslen.insert(make_pair(pos, len));
				pos = pos + len ;
			}
			len = 0;
			pos++;
		}
		number = number >> 1;
	}
	if (len != 0)
		poslen.insert(make_pair(pos, len));
	len = 0;
	map<int, int> :: iterator it;
	int curr = 0;
	for(it = poslen.begin(); it!= poslen.end();it++)
		cout<<it->first<<" "<<it->second<<endl;
	for(it = poslen.begin(); it!= poslen.end();it++)
	{
		curr = it->first;
		if ( poslen.find(curr + it->second + 1)!= poslen.end())
		{
			int next = curr + it->second + 1;
			if ( len < poslen[curr] + poslen[next]+1)
				len = poslen[curr] + poslen[next]+1;
		}
	}
	return len;
}

int main() {
	cout<<longeststr(1775);
	return 0;
}
