class Solution {
public:
    int recursion(vector<vector<int>>& grid, int m, int n,vector<vector<int>>&dp) {
        if (m == 0 && n == 0) {
            return grid[0][0];
        }
        if (m < 0 || n < 0) {
            return INT_MAX; 
        }
        if(dp[m][n]!=-1){
           return dp[m][n];
        }
        
        return dp[m][n]=grid[m][n] + min(recursion(grid, m - 1, n,dp), recursion(grid, m, n - 1,dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return recursion(grid, m, n,dp);
    }
};