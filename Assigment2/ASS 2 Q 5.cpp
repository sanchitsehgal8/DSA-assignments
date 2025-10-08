#include<iostream>
using namespace std;

class DiagonalMatrix {
    int *arr;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if(i == j) {
            arr[i] = val;
        }
    }
    
    int get(int i, int j) {
        if(i == j) {
            return arr[i];
        }
        return 0;
    }
    
    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    cout << arr[i] << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

class TridiagonalMatrix {
    int *arr;
    int n;
public:
    TridiagonalMatrix(int size) {
        n = size;
        arr = new int[3*n-2];
        for(int i = 0; i < 3*n-2; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if(i - j == 1) {
            arr[i-1] = val;
        }
        else if(i == j) {
            arr[n-1+i] = val;
        }
        else if(j - i == 1) {
            arr[2*n-1+i] = val;
        }
    }
    
    int get(int i, int j) {
        if(i - j == 1) {
            return arr[i-1];
        }
        else if(i == j) {
            return arr[n-1+i];
        }
        else if(j - i == 1) {
            return arr[2*n-1+i];
        }
        return 0;
    }
    
    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

class LowerTriangularMatrix {
    int *arr;
    int n;
public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if(i >= j) {
            int index = i*(i+1)/2 + j;
            arr[index] = val;
        }
    }
    
    int get(int i, int j) {
        if(i >= j) {
            int index = i*(i+1)/2 + j;
            return arr[index];
        }
        return 0;
    }
    
    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

class UpperTriangularMatrix {
    int *arr;
    int n;
public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if(i <= j) {
            int index = n*i - i*(i-1)/2 + (j-i);
            arr[index] = val;
        }
    }
    
    int get(int i, int j) {
        if(i <= j) {
            int index = n*i - i*(i-1)/2 + (j-i);
            return arr[index];
        }
        return 0;
    }
    
    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

class SymmetricMatrix {
    int *arr;
    int n;
public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
        for(int i = 0; i < n*(n+1)/2; i++) {
            arr[i] = 0;
        }
    }
    
    void set(int i, int j, int val) {
        if(i >= j) {
            int index = i*(i+1)/2 + j;
            arr[index] = val;
        } else {
            int index = j*(j+1)/2 + i;
            arr[index] = val;
        }
    }
    
    int get(int i, int j) {
        if(i >= j) {
            int index = i*(i+1)/2 + j;
            return arr[index];
        } else {
            int index = j*(j+1)/2 + i;
            return arr[index];
        }
    }
    
    void display() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int choice, n;
    
    while(1) {
        cout << "\n1. Diagonal Matrix\n";
        cout << "2. Tridiagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
            cout << "Enter size: ";
            cin >> n;
            DiagonalMatrix dm(n);
            
            cout << "Enter diagonal elements:\n";
            for(int i = 0; i < n; i++) {
                int val;
                cin >> val;
                dm.set(i, i, val);
            }
            
            cout << "Matrix:\n";
            dm.display();
            cout << "Space used: " << n << " instead of " << n*n << endl;
        }
        else if(choice == 2) {
            cout << "Enter size: ";
            cin >> n;
            TridiagonalMatrix tdm(n);
            
            cout << "Enter elements row by row:\n";
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(i-j == 1 || i == j || j-i == 1) {
                        int val;
                        cin >> val;
                        tdm.set(i, j, val);
                    }
                }
            }
            
            cout << "Matrix:\n";
            tdm.display();
            cout << "Space used: " << 3*n-2 << " instead of " << n*n << endl;
        }
        else if(choice == 3) {
            cout << "Enter size: ";
            cin >> n;
            LowerTriangularMatrix ltm(n);
            
            cout << "Enter elements row by row:\n";
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= i; j++) {
                    int val;
                    cin >> val;
                    ltm.set(i, j, val);
                }
            }
            
            cout << "Matrix:\n";
            ltm.display();
            cout << "Space used: " << n*(n+1)/2 << " instead of " << n*n << endl;
        }
        else if(choice == 4) {
            cout << "Enter size: ";
            cin >> n;
            UpperTriangularMatrix utm(n);
            
            cout << "Enter elements row by row:\n";
            for(int i = 0; i < n; i++) {
                for(int j = i; j < n; j++) {
                    int val;
                    cin >> val;
                    utm.set(i, j, val);
                }
            }
            
            cout << "Matrix:\n";
            utm.display();
            cout << "Space used: " << n*(n+1)/2 << " instead of " << n*n << endl;
        }
        else if(choice == 5) {
            cout << "Enter size: ";
            cin >> n;
            SymmetricMatrix sm(n);
            
            cout << "Enter lower triangular elements row by row:\n";
            for(int i = 0; i < n; i++) {
                for(int j = 0; j <= i; j++) {
                    int val;
                    cin >> val;
                    sm.set(i, j, val);
                }
            }
            
            cout << "Matrix:\n";
            sm.display();
            cout << "Space used: " << n*(n+1)/2 << " instead of " << n*n << endl;
        }
        else if(choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}