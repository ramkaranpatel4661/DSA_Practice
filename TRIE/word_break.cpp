class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Build the Trie
        TrieNode* root = new TrieNode();
        for (string word : wordDict) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isWord = true;
        }

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string is valid

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue; // Skip if s[0..i-1] can't be segmented

            TrieNode* node = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (node->children[idx]==NULL) break; // No further words possible
                node = node->children[idx];
                if (node->isWord) {
                    dp[j + 1] = true; 
                    i=j;// Mark s[0..j] as segmentable
                }
            }
        }

        return dp[n];
    }
};