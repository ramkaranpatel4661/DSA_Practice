#include <iostream>
#include <vector>
#include <algorithm> // For max, min

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int current_max = nums[0], current_min = nums[0], max_product = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(current_max, current_min); // Handle negative numbers
            }
            current_max = max(nums[i], current_max * nums[i]);
            current_min = min(nums[i], current_min * nums[i]);
            max_product = max(max_product, current_max);
        }

        return max_product;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    int result = solution.maxProduct(nums);

    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}
