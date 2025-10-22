#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool canEatAll(vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int bananas : piles) {
        hours += ceil((double)bananas / k);  // time to finish this pile
        if (hours > h) return false;         // optimization: stop early
    }
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;                         // minimum possible speed
    int right = *max_element(piles.begin(), piles.end());  // maximum pile size
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canEatAll(piles, h, mid)) {
            result = mid;         // possible to eat with this speed, try smaller
            right = mid - 1;
        } else {
            left = mid + 1;       // need higher speed
        }
    }

    return result;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h) << endl;  // Output: 4
    return 0;
}
