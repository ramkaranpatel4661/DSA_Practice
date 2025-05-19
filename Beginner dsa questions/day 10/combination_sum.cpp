#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findcombinator(int i, vector<vector<int>>& ans, vector<int>& candidates, int target, vector<int>& temp) {
        if (i == candidates.size()) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            // Stay at the same index to allow reusing the same element
            findcombinator(i, ans, candidates, target - candidates[i], temp);
            temp.pop_back();
        }
        // Move to the next index
        findcombinator(i + 1, ans, candidates, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findcombinator(0, ans, candidates, target, temp);
        return ans;
    }
};

int main() {
    Solution sol;

    int n, target;
    cout << "Enter the number of candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
