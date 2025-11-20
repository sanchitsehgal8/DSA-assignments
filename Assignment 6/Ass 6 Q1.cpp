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
    DoublyList() { head = NULL; }

    void insertFirst(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
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

    void insertAfter(int key, int x) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (t) {
            Node* n = new Node(x);
            n->next = t->next;
            n->prev = t;
            if (t->next) t->next->prev = n;
            t->next = n;
        }
    }

    void insertBefore(int key, int x) {
        if (head && head->data == key) {
            insertFirst(x);
            return;
        }
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (t) {
            Node* n = new Node(x);
            n->next = t;
            n->prev = t->prev;
            t->prev->next = n;
            t->prev = n;
        }
    }

    void deleteNode(int key) {
        Node* t = head;
        while (t && t->data != key) t = t->next;
        if (!t) return;
        if (t->prev) t->prev->next = t->next;
        else head = t->next;
        if (t->next) t->next->prev = t->prev;
        delete t;
    }

    bool search(int key) {
        Node* t = head;
        while (t) {
            if (t->data == key) return true;
            t = t->next;
        }
        return false;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

class CircularList {
public:
    Node* head;
    CircularList() { head = NULL; }

    void insertFirst(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        n->next = head;
        t->next = n;
        head = n;
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

    void insertAfter(int key, int x) {
        Node* t = head;
        if (!t) return;
        do {
            if (t->data == key) {
                Node* n = new Node(x);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* t = head;
        Node* p = NULL;
        do {
            if (t->data == key) {
                if (t == head && t->next == head) {
                    delete t;
                    head = NULL;
                    return;
                }
                if (t == head) {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                    delete t;
                    return;
                }
                p->next = t->next;
                delete t;
                return;
            }
            p = t;
            t = t->next;
        } while (t != head);
    }

    bool search(int key) {
        if (!head) return false;
        Node* t = head;
        do {
            if (t->data == key) return true;
            t = t->next;
        } while (t != head);
        return false;
    }

    void display() {
        if (!head) {
            cout << endl;
            return;
        }
        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);
        cout << endl;
    }
};

int main() {
    DoublyList d;
    CircularList c;
    int ch, type, x, key;

    while (1) {
        cout << "1.Doubly 2.Circular 3.Exit\n";
        cin >> type;
        if (type == 3) break;

        cout << "1.Insert First 2.Insert Last 3.Insert After 4.Insert Before 5.Delete 6.Search 7.Display\n";
        cin >> ch;

        if (ch == 1) {
            cin >> x;
            if (type == 1) d.insertFirst(x);
            else c.insertFirst(x);
        }

        else if (ch == 2) {
            cin >> x;
            if (type == 1) d.insertLast(x);
            else c.insertLast(x);
        }

        else if (ch == 3) {
            cin >> key >> x;
            if (type == 1) d.insertAfter(key, x);
            else c.insertAfter(key, x);
        }

        else if (ch == 4) {
            cin >> key >> x;
            if (type == 1) d.insertBefore(key, x);
        }

        else if (ch == 5) {
            cin >> key;
            if (type == 1) d.deleteNode(key);
            else c.deleteNode(key);
        }

        else if (ch == 6) {
            cin >> key;
            cout << (type == 1 ? d.search(key) : c.search(key)) << endl;
        }

        else if (ch == 7) {
            if (type == 1) d.display();
            else c.display();
        }
    }
}
