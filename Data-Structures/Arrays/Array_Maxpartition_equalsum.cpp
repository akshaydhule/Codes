/*
//============================================================================
// Name        : Array_Maxpartition_equalsum.cpp
// Description : Hackerrank
 * Nikita just came up with a new array game. The rules are as follows:
Initially, there is an array, , containing  integers.
In each move, Nikita must partition the array into
non-empty parts such that the sum of the elements in the left partition
is equal to the sum of the elements in the right partition.
If Nikita can make such a move, she gets point; otherwise, the game ends.

After each successful move, Nikita discards either the left partition
or the right partition and continues playing by using the remaining partition
as array .
Nikita loves this game and wants your help getting the best score possible.
Given , can you find and print the maximum number of points she can score?

Sample Input
3
3
3 3 3
4
2 2 2 2
7
4 1 0 1 1 0 1
Sample Output
0
2
3
//============================================================================
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxpart(int *a, int l, int h)
{
    int sum = 0, temp =0;
    //get total sum
    for(int i=l;i<=h;i++)
    {
        sum += a[i];
    }
    //first element
    temp = a[l];
    sum = sum - a[l];

    int i=0;
    for(i=l+1;i<=h;i++)
    {
        if(temp==sum)
            break;
        if(temp<sum)
        {
            temp += a[i];
            sum -= a[i];
        }
        if(temp>sum)
            return 0;
    }
    //if all in one section
    if(i == h+1)
        return 0;

    return 1 + max(maxpart(a,l,i-1), maxpart(a,i,h));
}

int main() {
    int n=0;
    cin>>n;
    int *output = new int[n];
    for(int i=0;i<n;i++)
    {
        int no =0;
        int *a = new int[no];
        cin>>no;
        for(int j=0;j<no;j++)
        {
            cin>>a[j];
        }
        output[i] = maxpart(a, 0, no-1);
    }
    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<"\n";
    }
    return 0;
}

