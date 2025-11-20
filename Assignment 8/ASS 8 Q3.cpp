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
    else if (x > r->data) r->right = insertNode(r->right, x);
    return r;
}

Node* findMin(Node* r) {
    while (r && r->left) r = r->left;
    return r;
}

Node* deleteNode(Node* r, int x) {
    if (!r) return r;
    if (x < r->data) r->left = deleteNode(r->left, x);
    else if (x > r->data) r->right = deleteNode(r->right, x);
    else {
        if (!r->left && !r->right) return NULL;
        else if (!r->left) return r->right;
        else if (!r->right) return r->left;
        Node* t = findMin(r->right);
        r->data = t->data;
        r->right = deleteNode(r->right, t->data);
    }
    return r;
}

int maxDepth(Node* r) {
    if (!r) return 0;
    int l = maxDepth(r->left);
    int ri = maxDepth(r->right);
    return (l > ri ? l : ri) + 1;
}

int minDepth(Node* r) {
    if (!r) return 0;
    int l = minDepth(r->left);
    int ri = minDepth(r->right);
    if (!r->left) return ri + 1;
    if (!r->right) return l + 1;
    return (l < ri ? l : ri) + 1;
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

    root = deleteNode(root, 30);

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;
}
