#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& A, std::string searchWord) {
        std::sort(A.begin(), A.end());
        std::vector<std::vector<std::string>> res;
        std::string cur = "";
        auto it = A.begin();

        for (char c : searchWord) {
            cur += c;
            std::vector<std::string> suggested;
            it = std::lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); ++i) {
                const std::string& s = *(it + i);
                if (s.substr(0, cur.size()) != cur) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }

        return res;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    std::string searchWord = "mouse";

    std::vector<std::vector<std::string>> result = solution.suggestedProducts(products, searchWord);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << "Suggestions after typing '" << searchWord.substr(0, i + 1) << "': ";
        for (const std::string& word : result[i]) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
