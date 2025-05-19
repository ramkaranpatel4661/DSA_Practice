#include <iostream>
#include <vector>
using namespace std;

void recursion(vector<int>& arr, vector<int>& sumofsubsets, vector<int>& temp, int i) {
    if (i == arr.size()) {
        int sum = 0;
        for (int j = 0; j < temp.size(); j++) {
            sum += temp[j];
        }
        sumofsubsets.push_back(sum);
        return;
    }
    temp.push_back(arr[i]);
    recursion(arr, sumofsubsets, temp, i + 1);
    temp.pop_back();
    recursion(arr, sumofsubsets, temp, i + 1);
}

vector<int> subsetSums(vector<int>& arr) {
    vector<int> temp;
    vector<int> sumofsubsets;
    recursion(arr, sumofsubsets, temp, 0);
    return sumofsubsets;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = subsetSums(arr);

    cout << "Subset sums are:" << endl;
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
