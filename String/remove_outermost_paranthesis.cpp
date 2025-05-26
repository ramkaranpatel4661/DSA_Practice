class Solution {
public:
    string removeOuterParentheses(string s) {
        int openbracket = 0;
        int closedbracket = 0;
        string ans = "";
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                openbracket++;
                if (flag) {
                    ans.push_back(s[i]);
                }
                flag = true;
            } else {
                closedbracket++;
                 if (openbracket == closedbracket) {
                      flag = false;
                 } else {
                 ans.push_back(s[i]);
            }
            }
           
        }
        return ans;
    }
};