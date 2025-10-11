#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            if (area > maxArea) {
                maxArea = area;
            }

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum water container area: " << s.maxArea(height);
    return 0;
}
