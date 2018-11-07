//============================================================================
// Name        : Matrix-CountBattleships.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int countBattleships(vector<vector<int>>& board) {
    int count = 0;
    int rows = board.size();
    int cols = board[0].size();
    cout<<rows<<" "<<cols<<endl;
    if(rows == 0)
        return count;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(board[i][j] == 1)
            {
                if(i>0 && board[i-1][j] == 1)
                    continue;
                else if(j>0 && board[i][j-1] == 1)
                    continue;
                else
                {
                	cout<<i<<" "<<j<<endl;
                    count += 1;
                }
            }
        }
    }
    return count;
}

int main() {
	vector<vector<int>> board = {
			{0,1,0,0,1},
			{0,1,0,0,1},
			{0,0,0,0,1},
			{1,0,1,1,0},
			{1,0,0,0,1},
	};
	cout<<countBattleships(board);
	return 0;
}
