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

Node* insertNode(int x) {
    return new Node(x);
}

void preorder(Node* r) {
    if (!r) return;
    cout << r->data << " ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

int main() {
    Node* root = insertNode(10);
    root->left = insertNode(20);
    root->right = insertNode(30);
    root->left->left = insertNode(40);
    root->left->right = insertNode(50);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}
