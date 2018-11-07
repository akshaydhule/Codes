//============================================================================
// Name        : Array-StockTrading.cpp
// Description : Buy and sell stocks
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int MaxProfit(vector<int> input, int k)
{
	int size = input.size();
	vector<vector<int>> profit;
	for(int i=0; i<=k; i++)
	{
		vector<int> temp(size+1, INT_MIN);
		profit.push_back(temp);
	}
	for(int i=0; i<=k; i++)
	{
		profit[i][0] = 0;
	}

	for(int j=0; j<size; j++)
	{
		profit[0][j] = 0;
	}

	for(int i=1; i<=k; i++)
	{
		int BuyDiff = INT_MIN;
		for(int j=1; j<size; j++)
		{
			//Max money in account with buying 1 stock
			BuyDiff = max(BuyDiff, profit[i-1][j-1] - input[j-1]);
			//Max money in account with or without trading 1 more stock
			profit[i][j] = max(profit[i][j-1], BuyDiff + input[j]);
		}
	}
	return profit[k][size-1];
}

int main() {
	cout<<MaxProfit({12, 14, 17, 10, 14, 13, 12, 15}, 3);
	return 0;
}
