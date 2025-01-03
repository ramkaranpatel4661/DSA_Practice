#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    vector<int> unions;
    int i = 0, j = 0;

    // Traverse both arrays
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (unions.empty() || unions.back() != a[i]) {
                unions.push_back(a[i]);
            }
            i++;
        } else if (a[i] > b[j]) {
            if (unions.empty() || unions.back() != b[j]) {
                unions.push_back(b[j]);
            }
            j++;
        } else { // a[i] == b[j]
            if (unions.empty() || unions.back() != a[i]) {
                unions.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from array `a`
    while (i < m) {
        if (unions.empty() || unions.back() != a[i]) {
            unions.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from array `b`
    while (j < n) {
        if (unions.empty() || unions.back() != b[j]) {
            unions.push_back(b[j]);
        }
        j++;
    }

    return unions;
}

int main() {
    int m, n;

    // Input size and elements for the first array
    cout << "Enter the size of the first array: ";
    cin >> m;
    vector<int> a(m);
    cout << "Enter elements of the first array in sorted order: ";
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    // Input size and elements for the second array
    cout << "Enter the size of the second array: ";
    cin >> n;
    vector<int> b(n);
    cout << "Enter elements of the second array in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Find and print the union of the two arrays
    vector<int> result = findUnion(a, b);
    cout << "Union of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
