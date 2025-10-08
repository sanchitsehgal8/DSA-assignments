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
        if(top == size - 1) {
            return;
        }
        top++;
        arr[top] = val;
    }
    
    int pop() {
        if(top == -1) {
            return 0;
        }
        int val = arr[top];
        top--;
        return val;
    }
    
    int isEmpty() {
        return top == -1;
    }
};

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int performOperation(int a, int b, char op) {
    if(op == '+') {
        return a + b;
    }
    else if(op == '-') {
        return a - b;
    }
    else if(op == '*') {
        return a * b;
    }
    else if(op == '/') {
        return a / b;
    }
    else if(op == '^') {
        int result = 1;
        for(int i = 0; i < b; i++) {
            result *= a;
        }
        return result;
    }
    return 0;
}

int evaluatePostfix(char postfix[]) {
    int len = 0;
    while(postfix[len] != '\0') {
        len++;
    }
    
    Stack s(len);
    
    for(int i = 0; i < len; i++) {
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            s.push(postfix[i] - '0');
        }
        else if(isOperator(postfix[i])) {
            int b = s.pop();
            int a = s.pop();
            int result = performOperation(a, b, postfix[i]);
            s.push(result);
        }
    }
    
    return s.pop();
}

int main() {
    char postfix[100];
    
    cout << "Enter postfix expression: ";
    cin >> postfix;
    
    int result = evaluatePostfix(postfix);
    
    cout << "Result: " << result << endl;
    
    return 0;
}