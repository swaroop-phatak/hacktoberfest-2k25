#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0, high = m * n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midVal = matrix[mid / n][mid % n];  // convert to 2D index

        if (midVal == target)
            return true;
        else if (midVal < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    int target = 3;

    if (searchMatrix(matrix, target))
        cout << "Target found!" << endl;
    else
        cout << "Target not found!" << endl;

    return 0;
}
