#include <iostream>
using namespace std;

int minFlips(int a, int b, int c) {
    int flips = 0;

    for (int i = 0; i < 32; ++i) {
        // Extract ith bit of a, b, and c
        int abit = (a >> i) & 1;
        int bbit = (b >> i) & 1;
        int cbit = (c >> i) & 1;

        if ((abit | bbit) != cbit) {
            if (cbit == 1) {
                // We need to flip both a and b to get 1 (if both are 0)
                flips += 1;
            } else {
                // cbit == 0: We need to flip all 1s to 0
                flips += abit + bbit;
            }
        }
    }

    return flips;
}

int main() {
    int a = 2, b = 6, c = 5;
    cout << "Minimum flips needed: " << minFlips(a, b, c) << endl;
    return 0;
}
