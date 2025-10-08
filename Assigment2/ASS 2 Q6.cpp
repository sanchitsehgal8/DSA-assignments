#include<iostream>
using namespace std;

class SparseMatrix {
public:
    int row, col, num;
    int data[100][3];
    
    SparseMatrix() {
        row = 0;
        col = 0;
        num = 0;
    }
    
    void read() {
        cout << "Enter number of rows: ";
        cin >> row;
        cout << "Enter number of columns: ";
        cin >> col;
        cout << "Enter number of non-zero elements: ";
        cin >> num;
        
        cout << "Enter row, column and value:\n";
        for(int i = 0; i < num; i++) {
            cin >> data[i][0] >> data[i][1] >> data[i][2];
        }
    }
    
    void display() {
        cout << "Row\tCol\tValue\n";
        for(int i = 0; i < num; i++) {
            cout << data[i][0] << "\t" << data[i][1] << "\t" << data[i][2] << endl;
        }
    }
    
    void displayMatrix() {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int found = 0;
                for(int k = 0; k < num; k++) {
                    if(data[k][0] == i && data[k][1] == j) {
                        cout << data[k][2] << " ";
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
    
    SparseMatrix transpose() {
        SparseMatrix result;
        result.row = col;
        result.col = row;
        result.num = num;
        
        int pos = 0;
        for(int i = 0; i < col; i++) {
            for(int j = 0; j < num; j++) {
                if(data[j][1] == i) {
                    result.data[pos][0] = data[j][1];
                    result.data[pos][1] = data[j][0];
                    result.data[pos][2] = data[j][2];
                    pos++;
                }
            }
        }
        
        return result;
    }
    
    SparseMatrix add(SparseMatrix b) {
        SparseMatrix result;
        
        if(row != b.row || col != b.col) {
            cout << "Matrix dimensions don't match!\n";
            return result;
        }
        
        result.row = row;
        result.col = col;
        
        int i = 0, j = 0, k = 0;
        
        while(i < num && j < b.num) {
            if(data[i][0] < b.data[j][0]) {
                result.data[k][0] = data[i][0];
                result.data[k][1] = data[i][1];
                result.data[k][2] = data[i][2];
                i++;
                k++;
            }
            else if(data[i][0] > b.data[j][0]) {
                result.data[k][0] = b.data[j][0];
                result.data[k][1] = b.data[j][1];
                result.data[k][2] = b.data[j][2];
                j++;
                k++;
            }
            else {
                if(data[i][1] < b.data[j][1]) {
                    result.data[k][0] = data[i][0];
                    result.data[k][1] = data[i][1];
                    result.data[k][2] = data[i][2];
                    i++;
                    k++;
                }
                else if(data[i][1] > b.data[j][1]) {
                    result.data[k][0] = b.data[j][0];
                    result.data[k][1] = b.data[j][1];
                    result.data[k][2] = b.data[j][2];
                    j++;
                    k++;
                }
                else {
                    int sum = data[i][2] + b.data[j][2];
                    if(sum != 0) {
                        result.data[k][0] = data[i][0];
                        result.data[k][1] = data[i][1];
                        result.data[k][2] = sum;
                        k++;
                    }
                    i++;
                    j++;
                }
            }
        }
        
        while(i < num) {
            result.data[k][0] = data[i][0];
            result.data[k][1] = data[i][1];
            result.data[k][2] = data[i][2];
            i++;
            k++;
        }
        
        while(j < b.num) {
            result.data[k][0] = b.data[j][0];
            result.data[k][1] = b.data[j][1];
            result.data[k][2] = b.data[j][2];
            j++;
            k++;
        }
        
        result.num = k;
        return result;
    }
    
    SparseMatrix multiply(SparseMatrix b) {
        SparseMatrix result;
        
        if(col != b.row) {
            cout << "Matrix dimensions don't match for multiplication!\n";
            return result;
        }
        
        result.row = row;
        result.col = b.col;
        
        SparseMatrix bt = b.transpose();
        
        int k = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < bt.row; j++) {
                int sum = 0;
                
                for(int p = 0; p < num; p++) {
                    if(data[p][0] == i) {
                        for(int q = 0; q < bt.num; q++) {
                            if(bt.data[q][0] == j && data[p][1] == bt.data[q][1]) {
                                sum += data[p][2] * bt.data[q][2];
                            }
                        }
                    }
                }
                
                if(sum != 0) {
                    result.data[k][0] = i;
                    result.data[k][1] = j;
                    result.data[k][2] = sum;
                    k++;
                }
            }
        }
        
        result.num = k;
        return result;
    }
};

int main() {
    SparseMatrix m1, m2, result;
    int choice;
    
    while(1) {
        cout << "\n1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
            cout << "Enter first matrix:\n";
            m1.read();
            
            cout << "\nOriginal Matrix (Triplet):\n";
            m1.display();
            
            cout << "\nOriginal Matrix:\n";
            m1.displayMatrix();
            
            result = m1.transpose();
            
            cout << "\nTranspose (Triplet):\n";
            result.display();
            
            cout << "\nTranspose Matrix:\n";
            result.displayMatrix();
        }
        else if(choice == 2) {
            cout << "Enter first matrix:\n";
            m1.read();
            
            cout << "Enter second matrix:\n";
            m2.read();
            
            cout << "\nFirst Matrix:\n";
            m1.displayMatrix();
            
            cout << "\nSecond Matrix:\n";
            m2.displayMatrix();
            
            result = m1.add(m2);
            
            cout << "\nResult (Triplet):\n";
            result.display();
            
            cout << "\nResult Matrix:\n";
            result.displayMatrix();
        }
        else if(choice == 3) {
            cout << "Enter first matrix:\n";
            m1.read();
            
            cout << "Enter second matrix:\n";
            m2.read();
            
            cout << "\nFirst Matrix:\n";
            m1.displayMatrix();
            
            cout << "\nSecond Matrix:\n";
            m2.displayMatrix();
            
            result = m1.multiply(m2);
            
            cout << "\nResult (Triplet):\n";
            result.display();
            
            cout << "\nResult Matrix:\n";
            result.displayMatrix();
        }
        else if(choice == 4) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}