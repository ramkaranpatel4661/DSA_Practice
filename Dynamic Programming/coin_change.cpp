// class Solution {
// public:
//     int recursion(vector<int>& coins, int amount,vector<int>&dp) {
//         if (amount == 0) return 0;
//         if (amount < 0) return INT_MAX;

//         int minCoins = INT_MAX;
//         if(dp[amount]!=-1){return dp[amount];}
//         for (int i = 0; i < coins.size(); i++) {
//             int ans = recursion(coins, amount - coins[i],dp);
//             if (ans != INT_MAX) {
//                 minCoins = min(minCoins, 1 + ans);
               
//             }
//         }
//          dp[amount]=minCoins;
//         return dp[amount];
//     }

//     int coinChange(vector<int>& coins, int amount) {
       
//         vector<int>dp(amount+1,-1);
//          int result = recursion(coins, amount,dp);
//         return (result == INT_MAX) ? -1 : result;
//     }
// };
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
