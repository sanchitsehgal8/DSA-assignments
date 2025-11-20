#include<iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int size;
    
public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }
    
    void push(int val) {
        if(isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        top++;
        arr[top] = val;
        cout << val << " pushed to stack\n";
    }
    
    void pop() {
        if(isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
    }
    
    int isEmpty() {
        return top == -1;
    }
    
    int isFull() {
        return top == size - 1;
    }
    
    void display() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    void peek() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }
};

int main() {
    int size, choice, val;
    
    cout << "Enter stack size: ";
    cin >> size;
    
    Stack s(size);
    
    while(1) {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. IsEmpty\n";
        cout << "4. IsFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
        }
        else if(choice == 2) {
            s.pop();
        }
        else if(choice == 3) {
            if(s.isEmpty()) {
                cout << "Stack is empty\n";
            } else {
                cout << "Stack is not empty\n";
            }
        }
        else if(choice == 4) {
            if(s.isFull()) {
                cout << "Stack is full\n";
            } else {
                cout << "Stack is not full\n";
            }
        }
        else if(choice == 5) {
            s.display();
        }
        else if(choice == 6) {
            s.peek();
        }
        else if(choice == 7) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }
    
    return 0;
}