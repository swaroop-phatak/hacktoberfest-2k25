#include <bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '*') {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s = "leet**cod*e";
    cout << "Result after removing stars: " << removeStars(s) << endl;
    return 0;
}
