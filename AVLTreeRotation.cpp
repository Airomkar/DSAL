#include <iostream>
using namespace std;
class Node {
public:
 int key;
 int height;
 Node* left;
 Node* right;
 Node(int key) {
 this->key = key;
 this->left = NULL; // Replaced nullptr with
NULL
 this->right = NULL; // Replaced nullptr with
NULL
 this->height = 1;
 }
};
int getHeight(Node* node) {
 if (node == NULL) {
 return 0;
 }
return node->height;
}
int max(int a, int b) {
 return (a > b) ? a : b;
}
int getBalance(Node* node) {
 if (node == NULL) {
 return 0;
 }
 return getHeight(node->left) -
getHeight(node->right);
}
Node* rightRotate(Node* y) {
 Node* x = y->left;
 Node* T2 = x->right;
 x->right = y;
 y->left = T2;
 y->height = max(getHeight(y->left),
getHeight(y->right)) + 1;
 x->height = max(getHeight(x->left),
getHeight(x->right)) + 1;
 return x;
}
Node* leftRotate(Node* x) {
 Node* y = x->right;
Node* T2 = y->left;
 y->left = x;
 x->right = T2;
 y->height = max(getHeight(y->left),
getHeight(y->right)) + 1;
 x->height = max(getHeight(x->left),
getHeight(x->right)) + 1;
 return y;
}
Node* insert(Node* node, int key) {
 if (node == NULL) {
 return new Node(key);
 }
 if (key < node->key) {
 node->left = insert(node->left, key);
 } else if (key > node->key) {
 node->right = insert(node->right, key);
 } else {
 return node;
 }
 node->height = 1 + max(getHeight(node->left),
getHeight(node->right));
 int balance = getBalance(node);
 // Left-Left c
if (balance > 1 && key < node->left->key) {
 return rightRotate(node);
 }
 // Right-Right case
 if (balance < -1 && key > node->right->key) {
 return leftRotate(node);
 }
 // Right-Left case
 if (balance < -1 && key < node->right->key) {
 node->right = rightRotate(node->right);
 return leftRotate(node);
 }
 // Left-Right case
 if (balance > 1 && key > node->left->key) {
 node->left = leftRotate(node->left);
 return rightRotate(node);
 }
 return node;
}
void inorder(Node* root) {
 if (root != NULL) {
 inorder(root->left);
 cout << root->key << " ";
 inorder(root->right);
 }
}

int main() {
 Node* root = NULL;
 root = insert(root, 27);
 root = insert(root, 39);
 root = insert(root, 40);
 root = insert(root, 55);
 root = insert(root, 77);
 root = insert(root, 99);
 cout << "In-order sequence : ";
 inorder(root);
 cout << endl;
 return 0;
}
