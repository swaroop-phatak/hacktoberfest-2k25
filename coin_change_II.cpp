#include <iostream>
#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int n, int amount) {
        if (n == 0) return 0;
        if (amount == 0) return 1;
        if (coins[n - 1] > amount)
            return coinChange(coins, n - 1, amount);
        return coinChange(coins, n, amount - coins[n - 1]) + coinChange(coins, n - 1, amount);
    }

    int change(int amount, std::vector<int>& coins) {
        int n = coins.size();
        if (amount == 0) return 1;
        if (n == 0) return 0;
        return coinChange(coins, n, amount);
    }
};

int main() {
    Solution solution;
    std::vector<int> coins = {1, 2, 5};
    int amount = 5;

    int result = solution.change(amount, coins);
    std::cout << "Number of combinations: " << result << std::endl;

    return 0;
}
