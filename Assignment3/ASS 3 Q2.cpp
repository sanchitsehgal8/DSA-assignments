#include<iostream>
using namespace std;

class Stack {
    char *arr;
    int top;
    int size;
    
public:
    Stack(int s) {
        size = s;
        arr = new char[size];
        top = -1;
    }
    
    void push(char ch) {
        if(top == size - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        top++;
        arr[top] = ch;
    }
    
    char pop() {
        if(top == -1) {
            cout << "Stack Underflow!\n";
            return '\0';
        }
        char ch = arr[top];
        top--;
        return ch;
    }
    
    int isEmpty() {
        return top == -1;
    }
};

void reverseString(char str[]) {
    int len = 0;
    while(str[len] != '\0') {
        len++;
    }
    
    Stack s(len);
    
    for(int i = 0; i < len; i++) {
        s.push(str[i]);
    }
    
    for(int i = 0; i < len; i++) {
        str[i] = s.pop();
    }
}

int main() {
    char str[100];
    
    cout << "Enter a string: ";
    cin >> str;
    
    cout << "Original string: " << str << endl;
    
    reverseString(str);
    
    cout << "Reversed string: " << str << endl;
    
    return 0;
}