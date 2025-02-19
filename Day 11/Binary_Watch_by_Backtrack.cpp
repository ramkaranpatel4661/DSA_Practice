#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int index, int turnedOn, int hour, int minute, vector<int>& leds, vector<string>& ans) {
        if (turnedOn == 0) {
            if (hour < 12 && minute < 60) {
                ans.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
            }
            return;
        }

        for (int i = index; i < leds.size(); i++) {
            if (i < 4) 
                backtrack(i + 1, turnedOn - 1, hour + leds[i], minute, leds, ans);
            else 
                backtrack(i + 1, turnedOn - 1, hour, minute + leds[i], leds, ans);
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        vector<int> leds = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32}; // First 4 are hours, last 6 are minutes
        backtrack(0, turnedOn, 0, 0, leds, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    int turnedOn = 3;
    vector<string> result = sol.readBinaryWatch(turnedOn);
    for (string time : result) {
        cout << time << endl;
    }
    return 0;
}
