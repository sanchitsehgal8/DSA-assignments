#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of the circular queue

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "⚠️ The queue is full. You cannot insert " << value << ".\n";
            return;
        }
        if (front == -1) front = 0;  // first element
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << "✅ " << value << " has been added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "⚠️ The queue is empty. Nothing to remove.\n";
            return;
        }
        cout << "🗑️ " << arr[front] << " has been removed from the queue.\n";
        if (front == rear) {
            // only one element was left
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "⚠️ The queue is empty.\n";
            return;
        }
        cout << "👀 The front element is: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "⚠️ The queue is empty.\n";
            return;
        }
        cout << "📌 Queue elements are: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    cout << "==============================\n";
    cout << "   Circular Queue Operations   \n";
    cout << "==============================\n";

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "👉 Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << (q.isEmpty() ? "✔️ The queue is empty.\n" : "❌ The queue is not empty.\n");
                break;

            case 6:
                cout << (q.isFull() ? "✔️ The queue is full.\n" : "❌ The queue is not full.\n");
                break;

            case 0:
                cout << "👋 Exiting program... Goodbye!\n";
                break;

            default:
                cout << "⚠️ Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
