#include <iostream>
#include <vector>
using namespace std;

int findMissingLinear(const vector<int>& arr, int n) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

int findMissingBinary(const vector<int>& arr, int n) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 7};
    int n = 7;

    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    int missingLinear = findMissingLinear(arr, n);
    cout << "Missing Number (Linear Search): " << missingLinear << endl;

    int missingBinary = findMissingBinary(arr, n);
    cout << "Missing Number (Binary Search): " << missingBinary << endl;

    return 0;
}
