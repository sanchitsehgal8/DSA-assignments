#include <iostream>
using namespace std;

#define SIZE 5   // maximum size of queue

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    // Add element to queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue " << x << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
        cout << x << " enqueued successfully!" << endl;
    }

    // Remove element from queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued successfully!" << endl;
        if (front == rear) {
            // Reset queue
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Peek at front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main program
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n==== Queue Menu ====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
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
                if (q.isEmpty())
                    cout << "Queue is EMPTY!\n";
                else
                    cout << "Queue is NOT empty.\n";
                break;
            case 5:
                if (q.isFull())
                    cout << "Queue is FULL!\n";
                else
                    cout << "Queue is NOT full.\n";
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
