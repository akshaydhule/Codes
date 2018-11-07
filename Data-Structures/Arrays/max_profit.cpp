/*
//============================================================================
// Name        : max_profit.cpp
// Description : Say you have an array for which the ith element
 * is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//============================================================================
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
	int newbuy = 0, buy= - prices[0];
	int sell =0,  oldsell = 0 , newsell;
	for(unsigned int i=1;i<prices.size();i++)
	{
		newbuy = max(buy,(oldsell - prices[i]));
		oldsell = sell;
		newsell = max(sell,(buy + prices[i]));
		buy = newbuy;
		oldsell = sell;
		sell = newsell;
	}
	return newsell;
}

int main() {
	vector<int> prices;
	prices[0] = 1;prices[1] = 2;prices[2] = 3;
	prices[3] = 0;prices[4] = 2;
	cout << maxProfit(prices);
	return 0;
}
