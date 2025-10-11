#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // If n is already 0, we don't need to plant any flowers.
        if (n == 0) {
            return true;
        }

        int size = flowerbed.size();
        for (int i = 0; i < size; ++i) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left plot is empty (or if it's the edge).
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                // Check if the right plot is empty (or if it's the edge).
                bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);

                // If both sides are empty, we can plant a flower here.
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // Plant the flower.
                    n--;              // Decrement the count of flowers to plant.

                    // If we have planted all the required flowers, return true.
                    if (n == 0) {
                        return true;
                    }
                }
            }
        }

        // If we finish the loop and n > 0, we couldn't plant all flowers.
        return false;
    }
};
