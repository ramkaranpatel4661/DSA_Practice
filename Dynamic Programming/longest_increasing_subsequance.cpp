

// this is most optimal by binary search tree
class Solution {
public:
    int recursion(vector<int>& nums, int prev, int curr) {
        if (curr > nums.size() - 1) {
            return 0;
        }
        int include = 0;
        int exclude;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + recursion(nums, curr, curr + 1);
        }
        exclude = 0 + recursion(nums, prev, curr + 1);
        return max(include, exclude);
    }
    int memoization(vector<int>& nums, int prev, int curr,
                    vector<vector<int>>& dp) {
        if (curr > nums.size() - 1) {
            return 0;
        }
        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }
        int include = 0;
        int exclude;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + memoization(nums, curr, curr + 1, dp);
        }
        exclude = 0 + memoization(nums, prev, curr + 1, dp);
        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    // solve by tabulation
    int tabulation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {
                int include = 0;
                int exclude;
                if (j == -1 || nums[i] > nums[j]) {
                    include = 1 + dp[i+1][i + 1];
                }
                exclude = 0 + dp[i+1][j + 1];
                dp[i][j + 1] = max(include, exclude);
               
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        //int prev = -1;
       // int curr = 0;

        // return recursion(nums,prev,curr);
        // int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return memoization(nums,prev,curr,dp);
       // return tabulation(nums);
      vector<int>ans;
      ans.push_back(nums[0]);
      for(int i=1;i<nums.size();i++)  {
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index]=nums[i];
        }
      }
      return ans.size(); 
       }
};
#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // We maintain a vector "ans" where ans[i] will be
        // the smallest possible tail value of an increasing subsequence of length (i+1)

        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ans.back()) {
                // If current element is greater than the last element of the current LIS,
                // it can extend the LIS
                ans.push_back(nums[i]);
            } else {
                // Otherwise, find the first element in "ans" which is >= nums[i]
                // and replace it to maintain the smallest possible tail
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        // The size of "ans" will be the length of the Longest Increasing Subsequence
        return ans.size();
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}
