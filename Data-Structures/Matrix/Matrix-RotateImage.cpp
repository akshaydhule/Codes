//============================================================================
// Name        : Matrix-RotateImage.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int s = 0, e = size-1;
        size = size-1;
        while(s<=e)
        {
            for(int i = s; i<e; i++)
            {
                int temp = matrix[s][i];
                matrix[s][i] = matrix[size-i][s]; //bottom up
                matrix[size-i][s] = matrix[e][size-i]; // bottom left
                matrix[e][size-i] = matrix[i][e]; // top down
                matrix[i][e] = temp; // top right
            }
            s++;
            e--;
        }
    }
    void print(vector<vector<int>>& matrix) {
    	for(int i = 0; i<matrix.size(); i++)
    		for(int j = 0; j<matrix[0].size(); j++)
    			cout<<matrix[i][j]<<" ";
    	cout<<endl;
    }
};

int main() {
	Solution s;
	vector<vector<int>> input = {
			{1,2,3},
			{4,5,6},
			{7,8,9}
	};
	s.print(input);
	s.rotate(input);
	s.print(input);
	return 0;
}
