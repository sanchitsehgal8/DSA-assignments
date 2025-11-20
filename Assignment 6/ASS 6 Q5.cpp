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

class List {
public:
    Node* head;
    List() {
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
    }

    bool isCircular() {
        if (!head) return true;
        Node* t = head->next;
        while (t && t != head) t = t->next;
        return t == head;
    }
};

int main() {
    List l;

    l.insertLast(2);
    l.insertLast(4);
    l.insertLast(6);
    l.insertLast(7);
    l.insertLast(5);

    Node* t = l.head;
    while (t->next) t = t->next;
    t->next = l.head;

    cout << (l.isCircular() ? "True" : "False");
}
