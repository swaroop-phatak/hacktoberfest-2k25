#include <iostream>
#include <queue>
#include <string>
using namespace std;

string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> radiant, dire;

    // Step 1: Store indices of senators in respective queues
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') radiant.push(i);
        else dire.push(i);
    }

    // Step 2: Simulate rounds
    while (!radiant.empty() && !dire.empty()) {
        int rIndex = radiant.front(); radiant.pop();
        int dIndex = dire.front(); dire.pop();

        // The senator with smaller index bans the other
        if (rIndex < dIndex) radiant.push(rIndex + n);  // Goes to next round
        else dire.push(dIndex + n);
    }

    return radiant.empty() ? "Dire" : "Radiant";
}

int main() {
    string senate = "RDD";
    cout << "Winning Party: " << predictPartyVictory(senate) << endl;
    return 0;
}
