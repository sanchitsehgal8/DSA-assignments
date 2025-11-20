#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d) {
        data = d;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    DoublyList() {
        head = NULL;
    }

    void insertLast(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

    int size() {
        int c = 0;
        Node* t = head;
        while (t) {
            c++;
            t = t->next;
        }
        return c;
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

    int size() {
        if (!head) return 0;
        int c = 0;
        Node* t = head;
        do {
            c++;
            t = t->next;
        } while (t != head);
        return c;
    }
};

int main() {
    DoublyList d;
    CircularList c;

    d.insertLast(10);
    d.insertLast(20);
    d.insertLast(30);

    c.insertLast(5);
    c.insertLast(15);
    c.insertLast(25);
    c.insertLast(35);

    cout << d.size() << endl;
    cout << c.size() << endl;
}
