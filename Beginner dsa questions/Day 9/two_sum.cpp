#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = target - num;
            if (m.find(sum) != m.end()) {
                return {m[sum], i};
            }
            m[num] = i;
        }
        return {-1, -1};
    }
};

int main() {
    int n, target;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;
    vector<int> result = solution.twoSum(nums, target);

    if (result[0] != -1) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
