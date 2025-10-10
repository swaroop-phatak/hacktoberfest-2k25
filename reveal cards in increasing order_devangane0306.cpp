#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Sort the deck in descending order
        sort(deck.begin(), deck.end(), greater<int>());

        deque<int> dq;
        // Start with the largest card
        dq.push_front(deck[0]);

        // For the remaining cards
        for (int i = 1; i < deck.size(); ++i) {
            // Move the card from back to front simulating the reverse reveal steps
            dq.push_front(dq.back());
            dq.pop_back();
            // Place the current card at the front
            dq.push_front(deck[i]);
        }

        // Convert deque to vector for output
        return vector<int>(dq.begin(), dq.end());
    }
};

int main() {
    Solution solution;
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result = solution.deckRevealedIncreasing(deck);

    cout << "Deck order to reveal cards in increasing order:" << endl;
    for (int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
