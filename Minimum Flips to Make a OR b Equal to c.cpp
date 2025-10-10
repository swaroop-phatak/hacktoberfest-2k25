#include <iostream>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (a > 0 || b > 0 || c > 0) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if ((bitA | bitB) != bitC) {
                if (bitC == 1)
                    flips += 1; // both bits are 0
                else
                    flips += bitA + bitB; // flip all 1s to 0
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;
    }
};

int main() {
    Solution sol;

    int a1 = 2, b1 = 6, c1 = 5;
    cout << "Input: a = " << a1 << ", b = " << b1 << ", c = " << c1 << endl;
    cout << "Output: " << sol.minFlips(a1, b1, c1) << endl;

    int a2 = 4, b2 = 2, c2 = 7;
    cout << "\nInput: a = " << a2 << ", b = " << b2 << ", c = " << c2 << endl;
    cout << "Output: " << sol.minFlips(a2, b2, c2) << endl;

    int a3 = 1, b3 = 2, c3 = 3;
    cout << "\nInput: a = " << a3 << ", b = " << b3 << ", c = " << c3 << endl;
    cout << "Output: " << sol.minFlips(a3, b3, c3) << endl;

    return 0;
}
