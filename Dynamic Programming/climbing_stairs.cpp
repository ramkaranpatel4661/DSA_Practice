#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int recursion(int n, vector<int>& dp) {
        if (n == 0) { return 1; }
        if (n < 0) { return 0; }
        if (dp[n] != -1) { return dp[n]; }
        dp[n] = recursion(n - 1, dp) + recursion(n - 2, dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return recursion(n, dp);
    }
};

int main() {
    Solution sol;
    int n;
    
    cout << "Enter the number of stairs: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Number of stairs cannot be negative." << endl;
    } else {
        int ways = sol.climbStairs(n);
        cout << "Number of ways to climb " << n << " stairs: " << ways << endl;
    }
    
    return 0;
}