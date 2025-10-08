#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (head == NULL) head = n;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
}

void insertBefore(int val, int x) {
    if (head == NULL) return;
    if (head->data == val) {
        insertBegin(x);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next == NULL) return;
    Node* n = new Node;
    n->data = x;
    n->next = temp->next;
    temp->next = n;
}

void insertAfter(int val, int x) {
    Node* temp = head;
    while (temp != NULL && temp->data != val) temp = temp->next;
    if (temp == NULL) return;
    Node* n = new Node;
    n->data = x;
    n->next = temp->next;
    temp->next = n;
}

void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteNode(int val) {
    if (head == NULL) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next == NULL) return;
    Node* t = temp->next;
    temp->next = t->next;
    delete t;
}

void search(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) {
            cout << "Node found at position " << pos << endl;
            return;
        }
        pos++;
        temp = temp->next;
    }
    cout << "Node not found" << endl;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, x, val;
    while (true) {
        cout << "1.Insert Begin 2.Insert End 3.Insert Before 4.Insert After 5.Delete Begin 6.Delete End 7.Delete Node 8.Search 9.Display 10.Exit\n";
        cin >> ch;
        if (ch == 1) {
            cin >> x;
            insertBegin(x);
        } else if (ch == 2) {
            cin >> x;
            insertEnd(x);
        } else if (ch == 3) {
            cin >> val >> x;
            insertBefore(val, x);
        } else if (ch == 4) {
            cin >> val >> x;
            insertAfter(val, x);
        } else if (ch == 5) {
            deleteBegin();
        } else if (ch == 6) {
            deleteEnd();
        } else if (ch == 7) {
            cin >> val;
            deleteNode(val);
        } else if (ch == 8) {
            cin >> val;
            search(val);
        } else if (ch == 9) {
            display();
        } else break;
    }
}
