class Solution {
public:
    int recursion(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size() - 1) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {
            int nextPos = i + j;
            if (nextPos < nums.size()) {
                int jump = recursion(nums, nextPos, dp);
                if (jump != INT_MAX) {
                    ans = min(ans, 1 + jump);
                }
            }
        }
        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recursion(nums, 0, dp);
    }
};
