/*
//============================================================================
// Name        : Spotify_easy.cpp
// Description :
//============================================================================
*/
#include <iostream>
using namespace std;

/* Return : returns the number with reverse binary rep
 * Para : input number
 * Desc : bitwise left shift of input and get last bit,
 * add to output number and right shift
 */

int reverseBinary(int input)
{
	int output = 0;
	while(input>0)
	{
		output = output<<1;
		output = (output) | (input & 1);
		input = input>>1;
	}
	return output;
}

//main function
int main() {
	int input;
	cin>>input;
	cout<<reverseBinary(input);
	return 0;
}
