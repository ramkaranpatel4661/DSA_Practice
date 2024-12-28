#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        string s = "";
        sort(arr.begin(), arr.end()); // Sort the array lexicographically

        // Compare the first and last strings after sorting
        for (int i = 0; i < arr[0].size(); i++) {
            if (arr[0][i] == arr[arr.size() - 1][i]) {
                s += arr[0][i]; // Add matching characters to the prefix
            } else {
                break; // Stop if characters don't match
            }
        }
        return s;
    }
};

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> arr(n);
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    string result = sol.longestCommonPrefix(arr);

    cout << "Longest common prefix: " << result << endl;

    return 0;
}
