//============================================================================
// Name        : stringrotation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;

void stringrotation(string s1, string s2)
{
	s2 = s2+s2; //strcat(s2,s2);
	//cout<<s3;
	if(s2.find(s1)!=string::npos)
		cout<<"true";
	else
		cout<<"false";

}

int main() {
	string s1 = "asder";
	string s2 = "erasd";
	stringrotation(s1,s2);
	return 0;
}
