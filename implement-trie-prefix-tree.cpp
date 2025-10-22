#include <iostream>
#include <vector>
#include <string>

class TrieNode {
public:
    std::vector<TrieNode*> v;
    bool isEnd;

    TrieNode() : v(26, nullptr), isEnd(false) {}
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->v[idx] == nullptr) {
                node->v[idx] = new TrieNode();
            }
            node = node->v[idx];
        }
        node->isEnd = true;
    }

    bool search(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->v[idx] == nullptr) return false;
            node = node->v[idx];
        }
        return node->isEnd;
    }

    bool startsWith(std::string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (node->v[idx] == nullptr) return false;
            node = node->v[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    std::cout << std::boolalpha;
    std::cout << "Search 'apple': " << trie.search("apple") << std::endl;     // true
    std::cout << "Search 'app': " << trie.search("app") << std::endl;         // false
    std::cout << "StartsWith 'app': " << trie.startsWith("app") << std::endl; // true

    trie.insert("app");
    std::cout << "Search 'app' after insert: " << trie.search("app") << std::endl; // true

    return 0;
}
