#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

bool check(Node* root, int seen[], int& k) {
    if (root == NULL) return false;
    for (int i = 0; i < k; i++) {
        if (seen[i] == root->data) return true;
    }
    seen[k++] = root->data;
    return check(root->left, seen, k) || check(root->right, seen, k);
}

int main() {
    Node* a = new Node{5, NULL, NULL};
    Node* b = new Node{3, NULL, NULL};
    Node* c = new Node{7, NULL, NULL};
    Node* d = new Node{3, NULL, NULL};

    a->left = b;
    a->right = c;
    b->left = d;

    int seen[100];
    int k = 0;

    bool dup = check(a, seen, k);
    if (dup) cout << "Duplicates Found";
    else cout << "No Duplicates";

    return 0;
}
