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

void deleteKey(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* t = temp->next;
            temp->next = temp->next->next;
            delete t;
            count++;
        } else temp = temp->next;
    }
    cout << "Count: " << count << endl;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }
    cin >> key;
    deleteKey(key);
    cout << "Updated Linked List: ";
    display();
}
