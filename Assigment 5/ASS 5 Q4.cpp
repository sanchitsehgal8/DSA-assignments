#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

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

void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }
    reverseList();
    display();
}
