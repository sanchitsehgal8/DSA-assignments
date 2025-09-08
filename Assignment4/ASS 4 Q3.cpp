#include <iostream>
#include <queue>
using namespace std;

// Function to interleave first half and second half of the queue
void interleaveQueue(queue<int>& q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << " The queue has an odd number of elements, so it cannot be interleaved. " << endl;
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Put the first half into a separate queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Now interleave the two halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

// Utility function to display queue
void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, val;

    cout << "====== Interleave Queue Program ======\n";
    cout << "Enter even number of elements in the queue: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    cout << "\nOriginal Queue: ";
    display(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    display(q);

    return 0;
}
