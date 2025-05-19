#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> v(nums.size());
        v[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            v[i] = v[i - 1] + nums[i];
        }
        long long target = v[v.size() - 1];
        int count = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] >= target - v[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.waysToSplitArray(nums);

    cout << "Number of ways to split the array: " << result << endl;

    return 0;
}
