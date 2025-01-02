#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool palindrome(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int i = 0;
        string longest_string = "";
        while (i < s.length()) {
            int j = s.length() - 1;
            while (j >= 0) {
                if (s[i] == s[j]) {
                    if (palindrome(i, j, s)) {
                        string temp = s.substr(i, j - i + 1);
                        if (temp.length() > longest_string.length()) {
                            longest_string = temp;
                            break;
                        }
                    }
                }
                j--;
            }
            i++;
        }
        return longest_string;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution sol;
    string result = sol.longestPalindrome(input);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
