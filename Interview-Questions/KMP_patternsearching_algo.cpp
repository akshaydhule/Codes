/*
//============================================================================
// Name        : KMP_patternsearching_algo.cpp
// Description : KMP (Knuth Morris Pratt) Pattern Searching
	txt[] = "AAAAAAAAAAAAAAAAAB"
   pat[] = "AAAAB"

   txt[] = "ABABABCABABABCABABABC"
   pat[] =  "ABABAC"

   computeLPSarray : Calculates longest proper prefix.
   for ex: For the pattern “AABAACAABAA”, lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

   KMPalgo : Checks for ith ele of pattern matches with jth ele of text
   if find a mismatch,
//============================================================================

 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

void computeLPSarray(char *pattern, int *lps,  int pat_len)
{
	int i=1;
	int len=0;
	lps[len] = 0;
	while(i<pat_len)
	{
		if (pattern[i] == lps[len])
		{
			len +=1;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				lps[len] = lps [len-1];
			}
			else
			{
				lps[i] =0 ;
				i++;
			}
		}
	}
}

void KMPalgo(char *pattern, char *text)
{
	int pat_len = strlen(pattern);
	int text_len = strlen(text);
	int *lps = new int[pat_len];
	computeLPSarray(pattern,lps, pat_len);
	int i=0,j=0;
	while(j<text_len)
	{
		//match
		if(pattern[i]==text[j])
		{
			i++;
			j++;
		}
		if(i==pat_len)
		{
			cout<<"pattern found at:"<< j-i;
			i = lps[i-1];
		}
		//mismatch
		else if (pattern[i]!=text[j] && j<text_len)
		{
			if(i!=0)
				i = lps[i-1];
			else
				j++;
		}
	}
}



int main() {
	char * pattern = "ABABCABAB";
	char * text = "ABABDABACDABABCABAB";
	KMPalgo(pattern, text);
	return 0;
}
