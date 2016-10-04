/*
//============================================================================
// Name        : reverse_string_variation.cpp
// Description : given a string containing alphabets and
	special characters.
	1. in this case ignore the special characters and reverse only alphabets
	2. reverse only vowels in the string
//============================================================================
*/
#include <iostream>
#include <unordered_set>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

string reversestring(string s)
{
	string reverse;
	int j=s.size(), i=0;
	while(i<j)
	{
		if(isalpha(s[i]) && isalpha(s[j]))
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}
		else if(!isalpha(s[i]))
		{
			i++;
		}
		else if(!isalpha(s[j]))
		{
			j--;
		}
	}
	return s;
}
//variation to reverse only vowels in a string
bool isvowel(char s)
{
	unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	if(vowels.find(s)!=vowels.end())
		return true;
	return false;
}

string reversestring_vowel(string s)
{
	string reverse;
	int j=s.size(), i=0;
	while(i<j)
	{
		if(isvowel(s[i]) && isvowel(s[j]))
		{
			swap(s[i], s[j]);
			i++;
			j--;
		}
		else if(!isvowel(s[i]))
		{
			i++;
		}
		else if(!isvowel(s[j]))
		{
			j--;
		}
	}
	return s;
}


int main() {
	string s = "ab$d";
	string a = "abesdeeeooouuu";
	cout << reversestring_vowel(a);
	return 0;
}
