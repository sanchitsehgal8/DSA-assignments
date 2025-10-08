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

int isBalanced(char exp[]) {
    int len = 0;
    while(exp[len] != '\0') {
        len++;
    }
    
    Stack s(len);
    
    for(int i = 0; i < len; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            s.push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(s.isEmpty()) {
                return 0;
            }
            
            char top = s.pop();
            
            if(exp[i] == ')' && top != '(') {
                return 0;
            }
            if(exp[i] == '}' && top != '{') {
                return 0;
            }
            if(exp[i] == ']' && top != '[') {
                return 0;
            }
        }
    }
    
    return s.isEmpty();
}

int main() {
    char exp[100];
    
    cout << "Enter an expression: ";
    cin >> exp;
    
    if(isBalanced(exp)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }
    
    return 0;
}