/* Non-Recursive Program to delete an entire binary tree. */
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
/* Non-recursive function to delete an entire binary tree. */
void _deleteTree(Node *root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty queue for level order traversal
    queue<Node *> q;
 
    // Do level order traversal starting from root
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
 
        free(node);
    }
}
 
/* Deletes a tree and sets the root as NULL */
void deleteTree(Node** node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}
 
// Utility function to create a new tree Node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // create a binary tree
    Node *root =  newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);
 
    //delete entire binary tree
    deleteTree(&root);
 
    return 0;
}


