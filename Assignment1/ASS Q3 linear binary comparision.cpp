#include <iostream>
#include <vector>
using namespace std;

// (a) Linear Search O(n)
int findMissingLinear(const vector<int>& arr, int n) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != i + 1) {
            return i + 1; // missing number
        }
    }
    return n; // if last number is missing
}

// (b) Binary Search O(log n)
int findMissingBinary(const vector<int>& arr, int n) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // If value matches its index+1, missing is on the right
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        }
        // Otherwise missing number is on the left
        else {
            right = mid - 1;
        }
    }
    return left + 1; // missing number
}

int main() {
    // Example: n = 7, numbers should be 1 to 7 but 5 is missing
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
