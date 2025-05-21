#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    int distinctSubstrings;

    Trie() {
        root = new TrieNode();
        distinctSubstrings = 0;
    }

    void insert(const string &s) {
        TrieNode* curr = root;
        for (char c : s) {
            int index = c - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
                distinctSubstrings++; // Count only new nodes (unique substrings)
            }
            curr = curr->children[index];
        }
    }

    int countDistinctSubstrings(const string &s) {
        for (int i = 0; i < s.size(); i++) {
            insert(s.substr(i)); // Insert all suffixes
        }
        return distinctSubstrings+1;
    }
};

int countDistinctSubstring(string s) {
    Trie trie;
    return trie.countDistinctSubstrings(s);
}