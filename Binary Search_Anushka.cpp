#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // avoids overflow

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // target not found
}

// -- Example Usage
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;

    int index = binarySearch(arr, target);
    cout << "Index of " << target << ": " << index << endl; // Output: 3

    return 0;
}
