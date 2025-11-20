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

bool check(Node* r, Node*& prev) {
    if (!r) return true;
    if (!check(r->left, prev)) return false;
    if (prev && prev->data >= r->data) return false;
    prev = r;
    return check(r->right, prev);
}

bool isBST(Node* root) {
    Node* prev = NULL;
    return check(root, prev);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    cout << (isBST(root) ? "True" : "False");
}
