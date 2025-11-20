#include <iostream>
using namespace std;

void heapify(int a[], int n, int i) {
    int mx = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[mx]) mx = l;
    if (r < n && a[r] > a[mx]) mx = r;
    if (mx != i) {
        swap(a[i], a[mx]);
        heapify(a, n, mx);
    }
}

void heapifyMin(int a[], int n, int i) {
    int mn = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] < a[mn]) mn = l;
    if (r < n && a[r] < a[mn]) mn = r;
    if (mn != i) {
        swap(a[i], a[mn]);
        heapifyMin(a, n, mn);
    }
}

void heapSortInc(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void heapSortDec(int a[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapifyMin(a, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapifyMin(a, i, 0);
    }
}

int main() {
    int a1[] = {40, 10, 80, 20, 60};
    int n1 = 5;
    heapSortInc(a1, n1);
    for (int i = 0; i < n1; i++) cout << a1[i] << " ";
    cout << endl;

    int a2[] = {40, 10, 80, 20, 60};
    int n2 = 5;
    heapSortDec(a2, n2);
    for (int i = 0; i < n2; i++) cout << a2[i] << " ";
}
