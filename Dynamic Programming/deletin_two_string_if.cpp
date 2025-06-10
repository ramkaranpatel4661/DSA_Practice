class Solution {
public:
int recursion(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    if(i>s1.size()-1){
        return s2.size()-j;
    }
    if(j>s2.size()-1){
        return s1.size()-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    if(s1[i]==s2[j]){
        return recursion(s1,s2,i+1,j+1,dp);
    }
    
    else {
        int left=1+recursion(s1,s2,i+1,j,dp);
        int right=1+recursion(s1,s2,i,j+1,dp);
        return dp[i][j]= min(left,right);
    }
    return dp[i][j];
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recursion(word1,word2,0,0,dp);
    }
};