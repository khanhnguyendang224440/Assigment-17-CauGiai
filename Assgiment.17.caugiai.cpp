#include <iostream>
#include <string.h>
using namespace std;

// Cau truc node cua cay AVL
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};

// Ham lay chieu cao cua node
int height(Node* node) {
    return node == nullptr ? 0 : node->height;
}

// Ham tao mot node moi
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Ham tinh gia tri can bang (balance factor)
int getBalance(Node* node) {
    return node == nullptr ? 0 : height(node->left) - height(node->right);
}

// Ham xoay phai
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Ham xoay trai
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Ham chen mot node vao cay AVL
Node* insert(Node* node, int key) {
    if (node == nullptr) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Truong hop LL
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }

    // Truong hop RR
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }

    // Truong hop LR
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Truong hop RL
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Ham duyet cay theo thu tu giua (Inorder)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Ham chinh
int main() {
    Node* root = nullptr;

    return 0;
}

