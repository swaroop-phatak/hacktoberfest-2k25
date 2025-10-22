#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        int buy = INT_MIN;
        int sell = 0;

        for (int price : prices) {
            buy = std::max(buy, sell - price);
            sell = std::max(sell, buy + price - fee);
        }

        return sell;
    }
};

int main() {
    Solution solution;


    std::vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int profit = solution.maxProfit(prices, fee);
    std::cout << "Maximum Profit with transaction fee: " << profit << std::endl;

    return 0;
}
