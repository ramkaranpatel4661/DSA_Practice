class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "", ans = "";

        for (char c : s) {
            if (c == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }

        if (!word.empty()) st.push(word); 

        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) ans += " ";
        }

        return ans;
    }
};
