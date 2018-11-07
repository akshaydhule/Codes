/*
//============================================================================
// Name        : Matrix-SpiralMatrixIII.cpp
// Description : On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid.

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.*/
//URL : https://leetcode.com/problems/spiral-matrix-iii/description/
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> _spiralMatrixIII(int R, int C, int r0, int c0) {
    	vector<vector<int>> output;
    	vector<int> dr = {0,1,0,-1};
    	vector<int> dc = {1,0,-1,0};
    	for(int i=0; i<(R*C*2); i++)
    	{
    		int dk = 1 + i/2;
    		int rot = i % 4;
    		for(int j=0; j<dk; j++)
    		{
    			r0+= dr[rot];
    			c0+= dc[rot];
    			if(r0>=0 && r0<R && c0>=0 && c0<C)
    			{
    				vector<int> newpair;
    				newpair.push_back(r0);newpair.push_back(c0);
    				output.push_back(newpair);
    				if(output.size() == R*C)
    					return output;
    			}
    		}
     	}
    	return output;
    }

    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> output;
    	vector<int> dr = {0,1,0,-1};
    	vector<int> dc = {1,0,-1,0};
        vector<int> newpair;
        newpair.push_back(r0);newpair.push_back(c0);
        output.push_back(newpair);
        if (R * C == 1) return output;

    	for(int i=1; i<=2*(R+C); i += 2)
    	{
            for(int rot=0; rot<4; rot++)
            {
                int dk = i + rot/2;
                for(int j=0; j<dk; j++)
                {
                    r0+= dr[rot];
                    c0+= dc[rot];
                    if(r0>=0 && r0<R && c0>=0 && c0<C)
                    {
                        vector<int> newpair;
                        newpair.push_back(r0);newpair.push_back(c0);
                        output.push_back(newpair);
                        if(output.size() == R*C)
                            return output;
                    }
                }
            }
     	}
    	return output;
    }
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
