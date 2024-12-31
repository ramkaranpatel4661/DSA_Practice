#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       unordered_map<int, int> m;
       int count = 0;
       m[0] = 1;
       int prefix_sum = 0;

       for (int i = 0; i < nums.size(); i++) {
           prefix_sum += nums[i];
           int remove = prefix_sum - goal;
           count += m[remove];
           m[prefix_sum] += 1;
       }

       return count;
    }
};

int main() {
    int n, goal;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the binary array (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum (goal): ";
    cin >> goal;

    Solution solution;
    int result = solution.numSubarraysWithSum(nums, goal);

    cout << "Number of subarrays with sum " << goal << ": " << result << endl;

    return 0;
}
