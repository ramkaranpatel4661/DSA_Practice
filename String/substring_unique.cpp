class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> indexMap;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        if (indexMap.count(s[right])) {
            left = max(indexMap[s[right]] + 1, left);
        }
        indexMap[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
};