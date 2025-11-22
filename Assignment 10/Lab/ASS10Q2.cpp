#include <iostream>
using namespace std;

int hashSet[1000];

int main() {
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int n1 = 4, n2 = 4;

    for(int i=0;i<1000;i++) hashSet[i] = 0;

    for(int i=0;i<n1;i++) hashSet[A[i]] = 1;

    for(int i=0;i<n2;i++) {
        int x = B[i];
        if(hashSet[x] == 1) cout << x << " ";
    }

    return 0;
}
