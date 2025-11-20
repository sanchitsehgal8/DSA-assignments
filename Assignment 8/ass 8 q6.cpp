#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> h;

    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i+1; }
    int right(int i) { return 2*i+2; }

    void heapifyUp(int i) {
        while (i>0 && h[i] > h[parent(i)]) {
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int mx = i;

        if (l < h.size() && h[l] > h[mx]) mx = l;
        if (r < h.size() && h[r] > h[mx]) mx = r;

        if (mx != i) {
            swap(h[i], h[mx]);
            heapifyDown(mx);
        }
    }

public:
    void push(int x) {
        h.push_back(x);
        heapifyUp(h.size()-1);
    }

    int pop() {
        if (h.empty()) return -1;
        int t = h[0];
        h[0] = h.back();
        h.pop_back();
        heapifyDown(0);
        return t;
    }

    int top() {
        if (h.empty()) return -1;
        return h[0];
    }

    bool empty() {
        return h.empty();
    }

    void display() {
        for (int x : h) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    pq.push(40);
    pq.push(10);
    pq.push(50);
    pq.push(30);
    pq.push(20);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Top: " << pq.top() << endl;

    cout << "Removing: ";
    while (!pq.empty()) {
        cout << pq.pop() << " ";
    }
}
