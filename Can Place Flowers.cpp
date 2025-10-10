#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    
    for (int i = 0; i < size; i++) {
        if (flowerbed[i] == 0) {
            // Check left and right neighbors
            bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
            bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);

            if (emptyLeft && emptyRight) {
                flowerbed[i] = 1;  // Plant a flower
                n--;               // Reduce number of flowers to plant
            }
        }
        if (n <= 0) return true;  // Early exit if all flowers planted
    }

    return n <= 0;
}

int main() {
    vector<int> flowerbed = {1,0,0,0,1};
    int n = 1;

    if (canPlaceFlowers(flowerbed, n))
        cout << "Yes, you can plant " << n << " flowers." << endl;
    else
        cout << "No, you cannot plant " << n << " flowers." << endl;

    return 0;
}
