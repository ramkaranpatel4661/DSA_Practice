#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        vector<int> ans;
        vector<int> s;

        for (int num : nums2) {
            while (!s.empty() && s.back() < num) {
                nextGreater[s.back()] = num;
                s.pop_back();
            }
            s.push_back(num);
        }

        for (int num : s) {
            nextGreater[num] = -1;
        }

        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int n1, n2;
    cout << "Enter the size of nums1: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n1; ++i) {
        cin >> nums1[i];
    }

    cout << "Enter the size of nums2: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n2; ++i) {
        cin >> nums2[i];
    }

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
