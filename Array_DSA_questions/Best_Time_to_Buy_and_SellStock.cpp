#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*The approach involves iterating through the stock prices once,
 keeping track of the minimum price seen so far (minPrice)
  and calculating the profit at each step as current price - minPrice. 
  Update the maximum profit (Max_Profit) if the current profit is higher. 
  This ensures the solution is computed in 𝑂(𝑛)
  O(n) time with 𝑂(1) space.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max_Profit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                Max_Profit = max(Max_Profit, prices[i] - minPrice);
               
            }
        }
        return Max_Profit;
    }
};

int main() {
    int n;
    cout << "Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter the stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    Solution sol;
    int result = sol.maxProfit(prices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}
