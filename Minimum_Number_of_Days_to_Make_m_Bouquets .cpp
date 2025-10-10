#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    // Helper function to check if we can make 'm' bouquets after 'day' days.
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets_made = 0;
        int adjacent_flowers = 0;
        
        for (int current_bloom_day : bloomDay) {
            // Check if the flower has bloomed by the given day
            if (current_bloom_day <= day) {
                adjacent_flowers++;
            } else {
                // Reset counter if the adjacent chain is broken
                adjacent_flowers = 0;
            }
            
            // If we have enough adjacent flowers, make a bouquet
            if (adjacent_flowers == k) {
                bouquets_made++;
                adjacent_flowers = 0; // Reset for the next bouquet
            }
        }
        
        return bouquets_made >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // Impossible to make the bouquets if total flowers needed > available
        long long required_flowers = static_cast<long long>(m) * k;
        if (required_flowers > bloomDay.size()) {
            return -1;
        }

        // Define the search space for the binary search
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                // 'mid' is a possible answer, try for an even earlier day
                result = mid;
                high = mid - 1;
            } else {
                // 'mid' is not enough days, need to wait longer
                low = mid + 1;
            }
        }

        return result;
    }
};
