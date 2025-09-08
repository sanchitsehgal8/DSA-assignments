#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // safe mid calculation

        if (arr[mid] == target) {
            return mid;  // target found
        } else if (arr[mid] < target) {
            left = mid + 1;  // search in right half
        } else {
            right = mid - 1; // search in left half
        }
    }

    return -1; // target not found
}

// Optional: Linear search for comparison
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target;

    cout << "Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    cout << "Enter the number to search: ";
    cin >> target;

    // Binary Search
    int binResult = binarySearch(arr, target);
    if (binResult != -1) {
        cout << "✅ Binary Search: " << target << " found at index " << binResult << ".\n";
    } else {
        cout << "❌ Binary Search: " << target << " not found.\n";
    }

    // Linear Search (for comparison)
    int linResult = linearSearch(arr, target);
    if (linResult != -1) {
        cout << "🔹 Linear Search: " << target << " found at index " << linResult << ".\n";
    } else {
        cout << "🔹 Linear Search: " << target << " not found.\n";
    }

    return 0;
}
