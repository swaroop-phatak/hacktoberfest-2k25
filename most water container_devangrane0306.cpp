#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currHeight = min(height[left], height[right]);
            int currentArea = width * currHeight;
            maxWater = max(maxWater, currentArea);

            // Move the pointer with the shorter height inward
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return maxWater;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 8, 6, 4, 6, 5, 5};
    cout << "Maximum water container area: " << solution.maxArea(heights) << endl;
    return 0;
}

