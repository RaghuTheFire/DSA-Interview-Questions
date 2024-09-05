/**********************************************************************
Maximize profit by buying and selling stocks.
Example:
Input: prices = [6, 1, 3, 2, 5, 4]
Output: 4
Explanation:
Buy at 1, sell at 5, profit = 4.
************************************************************************/
#include <iostream>
#include <vector>
#include <limits.h>

int maxProfit(const std::vector<int>& prices) {
    int max_profit = 0;
    int min_price = INT_MAX;

    for (int price : prices) {
        if (price < min_price) {
            min_price = price;
        } else if (price - min_price > max_profit) {
            max_profit = price - min_price;
        }
    }
    return max_profit;
}

int main() {
    std::vector<int> prices = {6, 1, 3, 2, 5, 4};
    int profit = maxProfit(prices);
    std::cout << "Max profit: " << profit << std::endl;
    return 0;
}
