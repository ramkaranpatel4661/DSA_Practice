#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                if (nums[i] == 1) {
                    maxi = max(maxi, count + 1);
                } else {
                    maxi = max(maxi, count);
                }
            } else if (nums[i] == 1) {
                count++;
            } else {
                maxi = max(count, maxi);
                count = 0;
            }
        }
        return maxi;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array (only 0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Maximum number of consecutive 1s: " << result << endl;

    return 0;
}
