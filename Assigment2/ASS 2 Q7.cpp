#include<iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int inv_count = 0;
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }
    
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while(j <= right) {
        temp[k++] = arr[j++];
    }
    
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right) {
    int inv_count = 0;
    
    if(left < right) {
        int mid = (left + right) / 2;
        
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    
    return inv_count;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int countInversionsBruteForce(int arr[], int n) {
    int count = 0;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n, choice;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\n1. Brute Force Method\n";
    cout << "2. Merge Sort Method\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    if(choice == 1) {
        int result = countInversionsBruteForce(arr, n);
        cout << "Number of inversions: " << result << endl;
    }
    else if(choice == 2) {
        int arrCopy[n];
        for(int i = 0; i < n; i++) {
            arrCopy[i] = arr[i];
        }
        
        int result = countInversions(arrCopy, n);
        cout << "Number of inversions: " << result << endl;
    }
    else {
        cout << "Invalid choice\n";
    }
    
    return 0;
}