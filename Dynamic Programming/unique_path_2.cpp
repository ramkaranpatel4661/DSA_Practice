class Solution {
public:
int recursion(vector<vector<int>>& g,int m,int n,int i,int j,vector<vector<int>>&dp){
    if(i==m && j==n){
        return 1;
    }
    if(i>m || j>n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=0;
    int b=0;
    if(g[i][j]!=1){ a =recursion(g,m,n,i+1,j,dp); }
    if(g[i][j]!=1){ b =recursion(g,m,n,i,j+1,dp); }
    return dp[i][j] = a+b;
    
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size()-1;
        int n=obstacleGrid[0].size()-1;
        if(obstacleGrid[m][n]==1){
            return 0;
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return recursion(obstacleGrid,m,n,0,0,dp);
    }
};