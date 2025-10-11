#include <iostream>
#include <queue>
#include <string>
using namespace std;

string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> radiant, dire;

    // Store indices of Radiant and Dire senators
    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R')
            radiant.push(i);
        else
            dire.push(i);
    }

    // Simulate rounds
    while (!radiant.empty() && !dire.empty()) {
        int r = radiant.front();
        int d = dire.front();
        radiant.pop();
        dire.pop();

        // The senator with the smaller index acts first
        if (r < d) {
            radiant.push(r + n); // R bans D, and gets back in next round
        } else {
            dire.push(d + n);    // D bans R, and gets back in next round
        }
    }

    return radiant.empty() ? "Dire" : "Radiant";
}

int main() {
    string senate = "RDD";
    cout << "Winning party: " << predictPartyVictory(senate) << endl;
    return 0;
}
