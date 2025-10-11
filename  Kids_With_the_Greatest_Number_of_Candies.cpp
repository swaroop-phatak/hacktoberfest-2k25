#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }

        vector<bool> result;
        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};

void printVector(const vector<bool>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    cout << "Input: candies = [2, 3, 5, 1, 3], extraCandies = 3" << endl;
    vector<bool> result1 = sol.kidsWithCandies(candies1, extraCandies1);
    cout << "Output: ";
    printVector(result1); // Expected: [true, true, true, false, true]

    cout << "\n---" << endl;

    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    cout << "Input: candies = [4, 2, 1, 1, 2], extraCandies = 1" << endl;
    vector<bool> result2 = sol.kidsWithCandies(candies2, extraCandies2);
    cout << "Output: ";
    printVector(result2); // Expected: [true, false, false, false, false]
    
    return 0;
}
