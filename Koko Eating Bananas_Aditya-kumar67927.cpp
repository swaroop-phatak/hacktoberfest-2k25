#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int hours = 0;

        for (int pile : piles) {
            hours += (pile + mid - 1) / mid; // same as ceil(pile / mid)
        }

        if (hours <= h) {
            result = mid;         // try smaller k
            right = mid - 1;
        } else {
            left = mid + 1;       // need faster eating
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
