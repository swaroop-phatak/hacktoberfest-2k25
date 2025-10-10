#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;                       // Pointer at start
    int right = height.size() - 1;      // Pointer at end
    int maxWater = 0;

    while (left < right) {
        int width = right - left;       // Distance between lines
        int currentHeight = min(height[left], height[right]);
        int area = width * currentHeight;  // Area formed by two lines
        maxWater = max(maxWater, area);    // Update max area

        // Move the pointer pointing to smaller height
        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum Water that can be contained: " << maxArea(height) << endl;
    return 0;
}
