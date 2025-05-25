#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    bool flag;
    TrieNode* children[26];

    TrieNode() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
private:
    TrieNode* root;
    string ans;

public:
    Solution() {
        root = new TrieNode();
        ans = "";
    }

    void insert(vector<string>& words) {
        for (string& word : words) {
            TrieNode* curr = root;
            for (char ch : word) {
                int idx = ch - 'a';
                if (curr->children[idx] == NULL) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->flag = true;
        }
    }

    void backtrack(TrieNode* node, string temp) {
        if (node == NULL) return;

        for (int i = 0; i < 26; i++) {
            TrieNode* child = node->children[i];
            if (child != NULL && child->flag) {
                temp.push_back(i + 'a');  
                if (temp.length() > ans.length() || (temp.length() == ans.length() && temp < ans)) {
                    ans = temp;
                }
                backtrack(child, temp);         // explore
                temp.pop_back();                // undo choice (backtrack)
            }
        }
    }

    string longestString(vector<string>& words) {
        insert(words);
        string temp = "";
        backtrack(root, temp);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of words: ";
    cin >> n;
    vector<string> words(n);
    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution sol;
    string result = sol.longestString(words);
    cout << "Longest word that can be built one character at a time: " << result << endl;

    return 0;
}
