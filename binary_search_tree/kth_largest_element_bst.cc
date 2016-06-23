// C++ program to find k'th largest element in BST
#include <iostream>
using namespace std;

struct Node {
  int key;
  Node* left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item) {
  Node* temp = new Node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// A function to find k'th largest element in a given tree.
void kthLargestUtil(Node* root, int k, int& c) {
  if (root == NULL || c >= k) return;
  kthLargestUtil(root->right, k, c);
  c++;
  if (c == k) {
    cout << "K'th largest element is " << root->key << endl;
    return;
  }
  kthLargestUtil(root->left, k, c);
}

// Function to find k'th largest element
void kthLargest(Node* root, int k) {
  int c = 0;
  kthLargestUtil(root, k, c);
}

Node* insert(Node* node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  return node;
}

int main() {
  /* Let us create following BST
            50
         /     \
        30      70
       /  \    /  \
     20   40  60   80 */
  Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  int c = 0;
  for (int k = 1; k <= 7; k++) kthLargest(root, k);

  return 0;
}
