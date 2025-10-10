#include <iostream>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string result = "";
    int i = 0, j = 0;
    int n = word1.length(), m = word2.length();

    while (i < n || j < m) {
        if (i < n) {
            result += word1[i];
            i++;
        }
        if (j < m) {
            result += word2[j];
            j++;
        }
    }
    return result;
}

int main() {
    string s1 = "abc";
    string s2 = "defgh";
    cout << mergeAlternately(s1, s2) << endl;  // Output: adbecfgh
    return 0;
}
