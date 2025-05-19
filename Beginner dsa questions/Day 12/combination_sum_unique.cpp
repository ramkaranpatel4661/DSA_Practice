class Solution {
    public:
        void Backtracking(vector<vector<int>>& ans, vector<int>& temp, int i, vector<int>& candidates, int target) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }
            
            for (int j = i; j < candidates.size(); ++j) {
                if (j > i && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                
                if (candidates[j] <= target) {
                    temp.push_back(candidates[j]);
                    Backtracking(ans, temp, j + 1, candidates, target - candidates[j]);
                    temp.pop_back();
                }
            }
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> temp;
            Backtracking(ans, temp, 0, candidates, target);
            return ans;
        }
    };
    