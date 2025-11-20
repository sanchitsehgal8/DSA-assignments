#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertNode(Node* r, int x) {
    if (!r) return new Node(x);
    if (x < r->data) r->left = insertNode(r->left, x);
    else r->right = insertNode(r->right, x);
    return r;
}

Node* searchRec(Node* r, int x) {
    if (!r || r->data == x) return r;
    if (x < r->data) return searchRec(r->left, x);
    return searchRec(r->right, x);
}

Node* searchNonRec(Node* r, int x) {
    while (r) {
        if (x == r->data) return r;
        if (x < r->data) r = r->left;
        else r = r->right;
    }
    return NULL;
}

Node* findMin(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* findMax(Node* r) {
    while (r && r->right) r = r->right;
    return r;
}

Node* inorderSuccessor(Node* root, Node* n) {
    if (n->right) return findMin(n->right);
    Node* succ = NULL;
    while (root) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* n) {
    if (n->left) return findMax(n->left);
    Node* pred = NULL;
    while (root) {
        if (n->data > root->data) {
            pred = root;
            root = root->right;
        } else if (n->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    Node* r1 = searchRec(root, 40);
    Node* r2 = searchNonRec(root, 70);

    cout << (r1 ? "Found" : "Not Found") << endl;
    cout << (r2 ? "Found" : "Not Found") << endl;

    cout << findMin(root)->data << endl;
    cout << findMax(root)->data << endl;

    Node* s = inorderSuccessor(root, searchRec(root, 50));
    Node* p = inorderPredecessor(root, searchRec(root, 50));

    cout << (s ? s->data : -1) << endl;
    cout << (p ? p->data : -1) << endl;
}
