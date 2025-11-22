#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = 6;
    int freq[100000] = {0};

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == 1) {
            cout << arr[i];
            break;
        }
    }

    return 0;
}
