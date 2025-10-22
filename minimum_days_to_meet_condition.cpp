#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to check if we can make m bouquets in 'days' days
bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
    int bouquets = 0;
    int flowers = 0;

    for (int day : bloomDay) {
        if (day <= days) {
            flowers++;  // this flower has bloomed
            if (flowers == k) { // one bouquet ready
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0; // sequence broken
        }
        if (bouquets >= m) return true; // early exit if enough bouquets made
    }

    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long total = 1LL * m * k;
    if (total > bloomDay.size()) return -1; // not enough flowers

    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canMakeBouquets(bloomDay, m, k, mid)) {
            result = mid;       // possible, try smaller days
            right = mid - 1;
        } else {
            left = mid + 1;     // not enough bouquets, need more days
        }
    }

    return result;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << minDays(bloomDay, m, k) << endl;  // Output: 3
    return 0;
}
