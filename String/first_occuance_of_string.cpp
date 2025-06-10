
// File: Solution.cpp

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();

        if (n == 0) return 0;

        for (int i = 0; i <= m - n; i++) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }
        return -1;
    }
};
