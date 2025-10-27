/*
 * Description:
 * Koko loves to eat bananas. There are n piles of bananas, where piles[i] is
 * the number of bananas in the ith pile. Koko can choose an integer k as her
 * eating speed (bananas per hour). Each hour, she eats k bananas from a chosen
 * pile. If a pile has fewer than k bananas, she eats the whole pile that hour.
 *
 * Goal:
 * Find the minimum integer k such that Koko can eat all bananas within h hours.
 *
 * Approach:
 * - Use binary search to find the minimum k.
 * - Define a helper function `canFinish(piles, h, k)` that returns true if Koko
 *   can finish all piles at speed k within h hours.
 * - For binary search:
 *   1. Set left = 1, right = max(piles).
 *   2. While left <= right:
 *       - mid = (left + right) / 2
 *       - if canFinish(piles, h, mid) is true:
 *           - k might be smaller, so set right = mid - 1
 *           - update ans = mid
 *       - else:
 *           - increase k, set left = mid + 1
 * - Return ans as the minimum eating speed.
 *
 * Time Complexity: O(n * log(max(piles)))  
 *     - n for checking all piles each iteration
 *     - log(max(piles)) for binary search on k
 * Space Complexity: O(1)  // constant extra space
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int pile : piles) {
            hours += pile / k;
            if (pile % k != 0) hours++;
            if (hours > h) return false;
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles1, h1) << endl; // Output: 4

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles2, h2) << endl; // Output: 30

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles3, h3) << endl; // Output: 23

    return 0;
}
