//============================================================================
// Name        : Matrix-NumberOfIslands.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowsize = grid.size();
        if(rowsize == 0)
            return 0;
        int colsize = grid[0].size();
        queue<pair<int, int>> neighbours;
        int count = 0;
        for(int row = 0; row<rowsize; row++)
        {
            for(int col = 0; col<colsize; col++)
            {
                if(grid[row][col] == '1')
                {
                    count +=1;
                    grid[row][col] = '0';
                    neighbours.push({row, col});
                    while(!neighbours.empty())
                    {
                        pair<int, int> top = neighbours.front();
                        neighbours.pop();
                        int r = top.first, c = top.second;
                        if(r+1<rowsize && grid[r+1][c] == '1'){
                            grid[r+1][c] = '0';
                            neighbours.push({r+1, c});
                        }
                        if(r-1>=0 && grid[r-1][c] == '1'){
                            grid[r-1][c] = '0';
                            neighbours.push({r-1, c});
                        }
                        if(c+1<colsize && grid[r][c+1] == '1'){
                            grid[r][c+1] = '0';
                            neighbours.push({r, c+1});
                        }
                        if(c-1>=0 && grid[r][c-1] == '1'){
                            grid[r][c-1] = '0';
                            neighbours.push({r, c-1});
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
	Solution s;
	vector<vector<char>> input;
	s.numIslands(input);
	return 0;
}
