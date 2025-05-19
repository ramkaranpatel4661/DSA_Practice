#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void combination(int n, int k, string st, vector<string> &ans) {
        if (st.size() == n) {
            ans.push_back(st);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (st.empty() || st.back() != ch) {
                combination(n, k, st + ch, ans);
                if (ans.size() >= k) return; 
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        combination(n, k, "", ans);
        return (ans.size() >= k) ? ans[k - 1] : "";
    }
};

int main() {
    Solution sol;
    int n = 3, k = 5;
    cout << sol.getHappyString(n, k) << endl;
    return 0;
}
