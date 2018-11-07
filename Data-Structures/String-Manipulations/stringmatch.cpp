//============================================================================
// Name        : stringmatch.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
using namespace std;


bool stringmatch(string *s1, string *s2)
{
	std::unordered_map<char, int> map;
	std::unordered_map<char, int>::iterator it;
	if(s1.length()!=s2->length())
		return false;
	for(int i=0;i<s1->length();i++)
	{
		if(map.find(s1[i])!=map.end())
		{
			it = map.find(s1[i]);
			it->second = it->second +1;
			map.insert(std::make_pair(s1[i],it->second));
		}
		else
			map.insert(std::make_pair(s1[i],1));
	}
	for(int i=0;i<s2->length();i++)
	{
		it = map.find(s2[i])
		if(it!=map.end())
		{
			if(it->second==0)
				return false;
			else
				it->second = it->second-1;
				map.insert(std::make_pair(s2[i],it->second));
		}
	}
	return true;

}

int main() {
	string s1 = "hello";
	string s2 = "llohe";
	bool val = stringmatch(&s1,&s2);

	return 0;
}
