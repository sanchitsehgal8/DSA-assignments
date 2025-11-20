#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Initialize the array using a vector
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Bubble Sort Algorithm
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element is greater than the next
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted Array (Ascending Order): ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
