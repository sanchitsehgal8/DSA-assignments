#include<iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        int j;
        for(j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                break;
            }
        }
        if(i == j) {
            count++;
        }
    }
    
    return count;
}

int countDistinctSorted(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[i - 1]) {
            count++;
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
    
    cout << "\n1. Without Sorting\n";
    cout << "2. With Sorting\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    if(choice == 1) {
        int result = countDistinct(arr, n);
        cout << "Number of distinct elements: " << result << endl;
    }
    else if(choice == 2) {
        int arrCopy[n];
        for(int i = 0; i < n; i++) {
            arrCopy[i] = arr[i];
        }
        
        int result = countDistinctSorted(arrCopy, n);
        cout << "Number of distinct elements: " << result << endl;
    }
    else {
        cout << "Invalid choice\n";
    }
    
    return 0;
}