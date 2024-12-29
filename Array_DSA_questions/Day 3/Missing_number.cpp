#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int>& nums) {
    int missing = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == missing) {
            missing++;
        } else {
            return missing;
        }
    }
    return missing;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = missingNumber(nums);

    cout << "The smallest missing number is: " << result << endl;

    return 0;
}
