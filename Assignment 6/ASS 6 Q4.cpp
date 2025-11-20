#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char d) {
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

    void insertLast(char x) {
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

    bool isPalindrome() {
        if (!head) return true;
        Node* l = head;
        Node* r = head;
        while (r->next) r = r->next;
        while (l != r && r->next != l) {
            if (l->data != r->data) return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }
};

int main() {
    DoublyList d;
    d.insertLast('m');
    d.insertLast('a');
    d.insertLast('d');
    d.insertLast('a');
    d.insertLast('m');
    cout << (d.isPalindrome() ? "True" : "False");
}
