class Solution {
public:
int recursion(vector<vector<int>> & triangle,int n,int i,int j,vector<vector<int>>&dp){
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]= triangle[i][j] + min(recursion(triangle,n,i+1,j,dp),recursion(triangle,n,i+1,j+1,dp));

}
// solve by tabulation
int tabulation(vector<vector<int>>& triangle){
     int n=triangle.size();
     int m=triangle[n-1].size();
     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
     for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
     }
     return dp[0][0];
}
int SO(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle[n - 1]); // Copy last row

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }

    return dp[0];
}

    int minimumTotal(vector<vector<int>>& triangle) {
        // int n=triangle.size();
        // int m=triangle[n-1].size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return recursion(triangle,n,0,0,dp);
        //return tabulation(triangle);
        return SO(triangle);
    }
};