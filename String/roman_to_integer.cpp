class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int number = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && m[s[i]] < m[s[i + 1]]) {
                number += m[s[i + 1]] - m[s[i]];
                i++;
            } else {
                number += m[s[i]];
            }
        }

        return number;
    }
};
