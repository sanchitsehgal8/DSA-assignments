#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class CircularList {
public:
    Node* head;
    CircularList() {
        head = NULL;
    }

    void insertLast(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void displayRepeatHead() {
        if (!head) return;
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << head->data;
    }
};

int main() {
    CircularList c;
    c.insertLast(20);
    c.insertLast(100);
    c.insertLast(40);
    c.insertLast(80);
    c.insertLast(60);
    c.displayRepeatHead();
}
