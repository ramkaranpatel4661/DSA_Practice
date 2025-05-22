class Solution {
public:
    // int recursion(vector<int>&nums, int n,int index,vector<int>&dp){
    //     if(index>=n){
    //       return 0;
    //     }
    //     if(dp[index]!=-1){
    //         return dp[index];
    //     }
    //     int include=nums[index]+recursion(nums,n,index+2,dp);
    //     int exclude=0+recursion(nums,n,index+1,dp);
    //     dp[index]= max(include,exclude);
    //     return dp[index];
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();

        // if (n == 1) {
        //     return nums[0];
        // }

        // int prev = nums[0];
        // int curr = max(nums[0], nums[1]);

        // for (int i = 2; i < n; i++) {
        //     int temp = curr;
        //     curr = max(nums[i] + prev, curr);
        //     prev = temp;
        // }

        // return curr;
        vector<int>dp(n+1,-1);
        dp[n]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};