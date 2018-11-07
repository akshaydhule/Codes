//============================================================================
// Name        : Matrix-SpiralMatrix.cpp
// Description : Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//URL : https://leetcode.com/problems/spiral-matrix/description/
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowsize = matrix.size();
    vector<int> output;
    if(rowsize == 0)
        return output;
    int colsize = matrix[0].size();
    int row = 0, col = 0;
    int circle = 1;
    int minval = min(rowsize, colsize);
    int half = minval % 2 == 1 ? minval/2 + 1 : minval/2;
    while(circle <= half)
    {//One round clock-wise
        //top: change col [col to colsize-circle] - row[circle-1]
        while(col<colsize-circle+1)
        {
        	cout<<matrix[row][col]<<" ";
            output.push_back(matrix[row][col]);
            col++;
        }
        //right: change row [row to rowsize-circle] - col[colsize-circle]
        row++;
        col--;
        while(row<rowsize-circle+1)
        {
        	cout<<matrix[row][col]<<" ";
            output.push_back(matrix[row][col]);
            row++;
        }
        //bottom: change col [colsize-circle-1 to circle-1], row [rowsize-circle]
        row--;
        col--;
        while(col>=circle-1 && row>=half)
        {
        	cout<<matrix[row][col]<<" ";
            output.push_back(matrix[row][col]);
            col--;
        }
        //left: change row [rowsize-circle-1 to circle], col[circle-1]
        row--;
        col++;
        while(row>circle-1  && col<=half)
        {
        	cout<<matrix[row][col]<<" ";
            output.push_back(matrix[row][col]);
            row--;
        }
        col++;
        row++;
        circle++;
    }
    return output;
}

vector<int> spiralOrderII(vector<vector<int>> &matrix){
	vector<int> output;
	int rowsize = matrix.size();
	if(rowsize == 0)
		return output;
	int colsize = matrix[0].size();
	int rowstart = 0, rowend = rowsize-1;
	int colstart = 0, colend = colsize-1;
	while(colstart<=colend && rowstart<=rowend)
	{
		for(int i=colstart; i<=colend; i++)
			output.push_back(matrix[rowstart][i]);
		for(int i=rowstart + 1; i<=rowend; i++)
			output.push_back(matrix[i][colend]);

		if(colstart<colend && rowstart<rowend)
		{
			for(int i=colend-1; i>=colstart; i--)
				output.push_back(matrix[rowend][i]);
			for(int i=rowend-1; i>rowstart; i--)
				output.push_back(matrix[i][colstart]);
		}
		rowstart++;rowend--;
		colstart++;colend--;
	}
	return output;
}

int main() {
	vector<vector<int> > input = {
			{1},
			{5},
			{9}};
	vector<int> output = spiralOrderII(input);
	for(int i : output)
		cout<<i<<" ";
	return 0;
}
