//============================================================================
// Name        : String-ValidIP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isdigit(char* no)
{
	int count = 0;
	while(*no)
	{
		if(*no<'0' || *no>'9')
			return false;
		no++;
		count++;
	}
	if(count<4 && count >> 0)
		return true;
	return false;
}

bool ValidIP(string ip)
{
	if(!isdigit(ip[0]) || !isdigit(ip[ip.size()-1]))
		return false;
	char* charstring = (char*)ip.c_str();
	char* no = strtok(charstring,".");
	int count = 0;
	while(no)
	{
		if(!isdigit(no))
			return false;
		int value = atoi(no);
		if(value>255 or value<0)
			return false;
		no = strtok(NULL,".");
		count++;
	}
	if(count == 4)
		return true;
	return false;
}

int main() {
	string ip = "1.1.1.1";
	if(ValidIP(ip))
		cout<<"true";
	else
		cout<<"false";
	return 0;
}
