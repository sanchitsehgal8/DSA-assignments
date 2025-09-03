#include <iostream>
#include <vector>
using namespace std;

// (a) Diagonal Matrix
class DiagonalMatrix {
    vector<int> arr; // only n elements
public:
    DiagonalMatrix(int n) : arr(n, 0) {}
    void set(int i, int j, int val) {
        if (i == j) arr[i-1] = val;
    }
    int get(int i, int j) {
        return (i == j) ? arr[i-1] : 0;
    }
    void display(int n) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (b) Tri-diagonal Matrix
class TriDiagonalMatrix {
    vector<int> arr; // 3n - 2 elements
    int n;
public:
    TriDiagonalMatrix(int n) : n(n), arr(3*n-2, 0) {}
    void set(int i, int j, int val) {
        if (i-j==1) arr[i-2] = val;             // lower
        else if (i==j) arr[n+i-2] = val;        // main
        else if (j-i==1) arr[2*n+i-2] = val;    // upper
    }
    int get(int i, int j) {
        if (i-j==1) return arr[i-2];
        else if (i==j) return arr[n+i-2];
        else if (j-i==1) return arr[2*n+i-2];
        else return 0;
    }
    void display() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (c) Lower Triangular Matrix
class LowerTriangularMatrix {
    vector<int> arr;
    int n;
public:
    LowerTriangularMatrix(int n) : n(n), arr(n*(n+1)/2, 0) {}
    void set(int i, int j, int val) {
        if (i>=j) arr[i*(i-1)/2 + (j-1)] = val;
    }
    int get(int i, int j) {
        if (i>=j) return arr[i*(i-1)/2 + (j-1)];
        return 0;
    }
    void display() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (d) Upper Triangular Matrix
class UpperTriangularMatrix {
    vector<int> arr;
    int n;
public:
    UpperTriangularMatrix(int n) : n(n), arr(n*(n+1)/2, 0) {}
    void set(int i, int j, int val) {
        if (i<=j) arr[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = val;
    }
    int get(int i, int j) {
        if (i<=j) return arr[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
        return 0;
    }
    void display() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (e) Symmetric Matrix (store lower triangular part)
class SymmetricMatrix {
    vector<int> arr;
    int n;
public:
    SymmetricMatrix(int n) : n(n), arr(n*(n+1)/2, 0) {}
    void set(int i, int j, int val) {
        if (i>=j) arr[i*(i-1)/2 + (j-1)] = val;
        else arr[j*(j-1)/2 + (i-1)] = val;
    }
    int get(int i, int j) {
        if (i>=j) return arr[i*(i-1)/2 + (j-1)];
        else return arr[j*(j-1)/2 + (i-1)];
    }
    void display() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;

    cout << "Diagonal Matrix:" << endl;
    DiagonalMatrix d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,12);
    d.display(n);

    cout << "\nTri-diagonal Matrix:" << endl;
    TriDiagonalMatrix td(n);
    td.set(1,1,2); td.set(1,2,3); td.set(2,1,4); td.set(2,2,5); td.set(2,3,6);
    td.set(3,2,7); td.set(3,3,8); td.set(3,4,9); td.set(4,3,10); td.set(4,4,11);
    td.display();

    cout << "\nLower Triangular Matrix:" << endl;
    LowerTriangularMatrix lt(n);
    lt.set(1,1,1); lt.set(2,1,2); lt.set(2,2,3); lt.set(3,1,4); lt.set(3,2,5); lt.set(3,3,6);
    lt.set(4,1,7); lt.set(4,2,8); lt.set(4,3,9); lt.set(4,4,10);
    lt.display();

    cout << "\nUpper Triangular Matrix:" << endl;
    UpperTriangularMatrix ut(n);
    ut.set(1,1,1); ut.set(1,2,2); ut.set(1,3,3); ut.set(1,4,4);
    ut.set(2,2,5); ut.set(2,3,6); ut.set(2,4,7);
    ut.set(3,3,8); ut.set(3,4,9);
    ut.set(4,4,10);
    ut.display();

    cout << "\nSymmetric Matrix:" << endl;
    SymmetricMatrix sm(n);
    sm.set(1,1,1); sm.set(2,1,2); sm.set(2,2,3); sm.set(3,1,4);
    sm.set(3,2,5); sm.set(3,3,6); sm.set(4,1,7); sm.set(4,2,8); sm.set(4,3,9); sm.set(4,4,10);
    sm.display();

    return 0;
}
