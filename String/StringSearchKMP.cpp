//============================================================================
// Name        : StringSearchKMP.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<int> KMParray(string pattern)
{
	vector<int> KMP(pattern.size());
	KMP[0] = 0;
	int i = 1, len = 0;
	int val = pattern.size();
	while(i<pattern.size())
	{
		if(pattern[i] == pattern[len])
		{
			len++;
			KMP[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len = KMP[len-1];
			}
			else
			{
				KMP[i] = 0;
				i++;
			}
		}
	}
	return KMP;
}

vector<int> KMPsearch(string str, string pattern)
{
	vector<int> positions, KMP = KMParray(pattern);
	int pos = 0, i = 0;
	while(i < str.size())
	{
		if(str[i] == pattern[pos])
		{
			pos++;
			i++;
		}
		if(pos == pattern.size())
		{
			positions.push_back(i-pos+1);
			pos = KMP[pos-1];
		}
		else if(str[i] != pattern[pos] && i < str.size())
		{
			if(pos != 0)
				pos = pattern[pos-1];
			else
				i++;
		}
	}
	return positions;
}

int main() {
	string str = "AABAACAADAABAABA";
	string pattern = "AABA";
	vector<int> values = KMPsearch(str, pattern);
	int i= 0;
	while(i<values.size())
	{
		cout<<values[i]<<" ";
		i++;
	}
	return 0;
}
