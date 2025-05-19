#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int maxi = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            int count = 0;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '0') {
                    count++;
                }
            }
            for (int k = i + 1; k < s.length(); k++) {
                if (s[k] == '1') {
                    count++;
                }
            }
            maxi = max(count, maxi);
        }
        return maxi;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.maxScore(s) << endl;
    return 0;
}
