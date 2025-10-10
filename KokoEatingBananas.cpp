#include <bits/stdc++.h>
using namespace std;

bool canFinish(vector<int>& piles, int k, int h) {
    int hours = 0;
    for (int pile : piles) {
        hours += (pile + k - 1) / k; // Equivalent to ceil(pile / k)
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canFinish(piles, mid, h)) {
            result = mid;
            right = mid - 1; // Try to find smaller k
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum eating speed: " << minEatingSpeed(piles, h) << endl;

    return 0;
}
