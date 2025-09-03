#include <iostream>
#include <vector>
using namespace std;

// Triplet structure
struct Triplet {
    int row, col, val;
};

// Sparse Matrix class
class SparseMatrix {
    int rows, cols, terms;   // matrix dimensions and non-zero count
    vector<Triplet> data;    // triplet array

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), terms(0) {}

    void addElement(int r, int c, int val) {
        if (val != 0) {
            data.push_back({r, c, val});
            terms++;
        }
    }

    void display() {
        cout << "Row Col Val" << endl;
        for (auto &t : data) {
            cout << t.row << "   " << t.col << "   " << t.val << endl;
        }
    }

    // (a) Transpose
    SparseMatrix transpose() {
        SparseMatrix result(cols, rows);
        for (int c = 0; c < cols; c++) {
            for (auto &t : data) {
                if (t.col == c) {
                    result.addElement(t.col, t.row, t.val);
                }
            }
        }
        return result;
    }

    // (b) Addition of two sparse matrices
    SparseMatrix add(const SparseMatrix &other) {
        if (rows != other.rows || cols != other.cols) {
            throw runtime_error("Matrix dimensions must match for addition!");
        }

        SparseMatrix result(rows, cols);
        int i = 0, j = 0;

        while (i < data.size() && j < other.data.size()) {
            if (data[i].row < other.data[j].row ||
                (data[i].row == other.data[j].row && data[i].col < other.data[j].col)) {
                result.addElement(data[i].row, data[i].col, data[i].val);
                i++;
            }
            else if (data[i].row > other.data[j].row ||
                     (data[i].row == other.data[j].row && data[i].col > other.data[j].col)) {
                result.addElement(other.data[j].row, other.data[j].col, other.data[j].val);
                j++;
            }
            else {
                int sum = data[i].val + other.data[j].val;
                if (sum != 0)
                    result.addElement(data[i].row, data[i].col, sum);
                i++; j++;
            }
        }

        // Copy remaining
        while (i < data.size()) result.addElement(data[i].row, data[i].col, data[i++].val);
        while (j < other.data.size()) result.addElement(other.data[j].row, other.data[j].col, other.data[j++].val);

        return result;
    }

    // (c) Multiplication of two sparse matrices
    SparseMatrix multiply(const SparseMatrix &other) {
        if (cols != other.rows) {
            throw runtime_error("Invalid dimensions for multiplication!");
        }

        SparseMatrix result(rows, other.cols);

        for (auto &a : data) {
            for (auto &b : other.data) {
                if (a.col == b.row) {
                    // find if already exists in result
                    bool found = false;
                    for (auto &r : result.data) {
                        if (r.row == a.row && r.col == b.col) {
                            r.val += a.val * b.val;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        result.addElement(a.row, b.col, a.val * b.val);
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    // Example matrices
    SparseMatrix A(3, 3);
    A.addElement(0, 0, 5);
    A.addElement(0, 2, 8);
    A.addElement(1, 1, 3);

    SparseMatrix B(3, 3);
    B.addElement(0, 1, 6);
    B.addElement(1, 1, 7);
    B.addElement(2, 0, 4);

    cout << "Matrix A:" << endl;
    A.display();

    cout << "\nMatrix B:" << endl;
    B.display();

    cout << "\nTranspose of A:" << endl;
    A.transpose().display();

    cout << "\nA + B:" << endl;
    A.add(B).display();

    cout << "\nA * B:" << endl;
    A.multiply(B).display();

    return 0;
}
