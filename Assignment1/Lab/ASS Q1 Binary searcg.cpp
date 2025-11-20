#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const std::vector<int>& arr, int targetVal) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == targetVal) {
            return mid; // found
        }
        if (arr[mid] < targetVal) {
            left = mid + 1; // search right half
        } else {
            right = mid - 1; // search left half
        }
    }
    return -1; // not found
}

int main() {
    vector<int> myArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int myTarget = 15;

    int result = binarySearch(myArray, myTarget);

    if (result != -1) {
        cout << "Value " << myTarget << " found at index " << result << endl;
    } else {
        cout << "Target not found in array." << endl;
    }

    return 0;
}
