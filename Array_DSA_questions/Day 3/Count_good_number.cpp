#include <iostream>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modExp(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long oddCount = (n + 1) / 2;
        long long evenCount = n / 2;
        long long primesPower = modExp(5, oddCount, MOD);
        long long evensPower = modExp(4, evenCount, MOD);
        return (primesPower * evensPower) % MOD;
    }
};

int main() {
    long long n;
    cout << "Enter the length of the number: ";
    cin >> n;

    Solution solution;
    int result = solution.countGoodNumbers(n);

    cout << "The count of good numbers is: " << result << endl;

    return 0;
}
