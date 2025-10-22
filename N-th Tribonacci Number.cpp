#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int a = 0, b = 1, c = 1, d;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};

// Example usage
int main() {
    Solution sol;
    int n = 25;
    cout << sol.tribonacci(n) << endl; // Expected output: 1389537
    return 0;
}
