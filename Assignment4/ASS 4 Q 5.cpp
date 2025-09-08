#include <iostream>
#include <queue>
using namespace std;

/* ------------------------------
   Stack using TWO Queues
   ------------------------------ */
class StackTwoQueues {
    queue<int> q1, q2; // q1 holds the current stack, q2 is temporary

public:
    void push(int x) {
        // Add new element to q2 first
        q2.push(x);

        // Move everything from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 so q1 always has the stack
        swap(q1, q2);

        cout << "✅ Pushed " << x << " onto the stack.\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "⚠️ Stack is empty! Nothing to pop.\n";
            return;
        }
        cout << "🗑️ Popped " << q1.front() << " from the stack.\n";
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "⚠️ Stack is empty!\n";
            return;
        }
        cout << "👀 Top element: " << q1.front() << endl;
    }

    bool empty() {
        return q1.empty();
    }
};

/* ------------------------------
   Stack using ONE Queue
   ------------------------------ */
class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Rotate the queue to put the new element at front
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << "✅ Pushed " << x << " onto the stack.\n";
    }

    void pop() {
        if (q.empty()) {
            cout << "⚠️ Stack is empty! Nothing to pop.\n";
            return;
        }
        cout << "🗑️ Popped " << q.front() << " from the stack.\n";
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "⚠️ Stack is empty!\n";
            return;
        }
        cout << "👀 Top element: " << q.front() << endl;
    }

    bool empty() {
        return q.empty();
    }
};

/* ------------------------------
   MAIN MENU
   ------------------------------ */
int main() {
    StackTwoQueues stack2;
    StackOneQueue stack1;

    int implChoice, choice, value;

    cout << "===== STACK USING QUEUES =====\n";
    cout << "Choose implementation:\n";
    cout << "1. Stack using TWO Queues\n";
    cout << "2. Stack using ONE Queue\n";
    cout << "👉 Enter your choice: ";
    cin >> implChoice;

    cout << "\n--- Stack Operations Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Top\n";
    cout << "4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> value;
            if (implChoice == 1) stack2.push(value);
            else stack1.push(value);
        }
        else if (choice == 2) {
            if (implChoice == 1) stack2.pop();
            else stack1.pop();
        }
        else if (choice == 3) {
            if (implChoice == 1) stack2.top();
            else stack1.top();
        }
        else if (choice == 4) {
            cout << " Exiting program. Goodbye!\n";
            break;
        }
        else {
            cout << " Invalid choice. Try again!\n";
        }
    }

    return 0 ;
}
