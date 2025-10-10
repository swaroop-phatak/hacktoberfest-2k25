#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int ast : asteroids) {
        bool alive = true;
        while (!st.empty() && st.top() > 0 && ast < 0) {
            if (abs(st.top()) < abs(ast)) {
                st.pop(); // top explodes, continue
            } else if (abs(st.top()) == abs(ast)) {
                st.pop(); // both explode
                alive = false;
                break;
            } else {
                alive = false; // current asteroid explodes
                break;
            }
        }
        if (alive) st.push(ast);
    }

    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main() {
    int n, temp;
    cout << "Enter number of asteroids: ";
    cin >> n;
    vector<int> asteroids;
    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        asteroids.push_back(temp);
    }

    vector<int> result = asteroidCollision(asteroids);
    cout << "Asteroids after collision: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
