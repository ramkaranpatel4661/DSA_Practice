#include <iostream>
#include <vector>
using namespace std;

bool recursion(vector<int> &a, vector<int> &temp, int k, int n, int i, int sum) {
    if (i == n) {
        return sum == k;
    }

    temp.push_back(a[i]);
    if (recursion(a, temp, k, n, i + 1, sum + a[i])) {
        return true;
    }
    temp.pop_back();

    if (recursion(a, temp, k, n, i + 1, sum)) {
        return true;
    }

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    vector<int> temp;
    int sum = 0;
    return recursion(a, temp, k, n, 0, sum);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (isSubsetPresent(n, k, a)) {
        cout << "Subset with sum " << k << " is present." << endl;
    } else {
        cout << "Subset with sum " << k << " is not present." << endl;
    }
    return 0;
}
