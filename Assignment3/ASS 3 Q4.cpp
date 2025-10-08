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
            return;
        }
        top++;
        arr[top] = ch;
    }
    
    char pop() {
        if(top == -1) {
            return '\0';
        }
        char ch = arr[top];
        top--;
        return ch;
    }
    
    int isEmpty() {
        return top == -1;
    }
    
    char peek() {
        if(top == -1) {
            return '\0';
        }
        return arr[top];
    }
};

int precedence(char op) {
    if(op == '^') {
        return 3;
    }
    else if(op == '*' || op == '/') {
        return 2;
    }
    else if(op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int len = 0;
    while(infix[len] != '\0') {
        len++;
    }
    
    Stack s(len);
    int j = 0;
    
    for(int i = 0; i < len; i++) {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= '0' && infix[i] <= '9')) {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(') {
            s.push(infix[i]);
        }
        else if(infix[i] == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop();
        }
        else if(isOperator(infix[i])) {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(infix[i])) {
                postfix[j++] = s.pop();
            }
            s.push(infix[i]);
        }
    }
    
    while(!s.isEmpty()) {
        postfix[j++] = s.pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    
    cout << "Enter infix expression: ";
    cin >> infix;
    
    infixToPostfix(infix, postfix);
    
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}