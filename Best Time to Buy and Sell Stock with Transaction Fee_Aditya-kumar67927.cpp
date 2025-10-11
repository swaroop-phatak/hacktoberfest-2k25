#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if (n == 0) return 0;

    int hold = -prices[0]; // We bought on day 0
    int cash = 0;          // No stock on day 0

    for (int i = 1; i < n; ++i) {
        hold = max(hold, cash - prices[i]);         // Either hold, or buy today
        cash = max(cash, hold + prices[i] - fee);   // Either rest, or sell today
    }

    return cash;
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Max profit with fee: " << maxProfit(prices, fee) << endl;
    return 0;
}
