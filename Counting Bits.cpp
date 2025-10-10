#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            bits[i] = bits[i >> 1] + (i & 1);
        return bits;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> result = sol.countBits(n);

    cout << "Input: " << n << endl;
    cout << "Output: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
