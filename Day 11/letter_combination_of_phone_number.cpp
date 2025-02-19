#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Backtracking(string temp, vector<string> &ans, string s, int ind, string &digits, map<int, string> &m) {
        if (temp.size() == digits.size()) {
            ans.push_back(temp);
            return;
        }
        for (char j : s) {
            temp += j;
            Backtracking(temp, ans, m[digits[ind + 1] - '0'], ind + 1, digits, m);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 

        map<int, string> m = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };

        vector<string> ans;
        string temp = "";

        Backtracking(temp, ans, m[digits[0] - '0'], 0, digits, m);
        return ans;
    }
};

int main() {
    Solution sol;
    string digits;
    cin >> digits;
    vector<string> result = sol.letterCombinations(digits);
    for (const string &s : result) {
        cout << s << " ";
    }
    return 0;
}
