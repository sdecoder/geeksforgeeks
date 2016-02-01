/* c++ program to convert Binary Tree into Doubly
   Linked List where the nodes are represented
   spirally. */
#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
/* Given a reference to the head of a list and a node,
inserts the node on the front of the list. */
void push(Node** head_ref, Node* node)
{
    // Make right of given node as head and left as
    // NULL
    node->right = (*head_ref);
    node->left = NULL;
 
    // change left of head node to given node
    if ((*head_ref) !=  NULL)
        (*head_ref)->left = node ;
 
    // move the head to point to the given node
    (*head_ref) = node;
}
 
// Function to prints contents of DLL
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}
 
/* Function to print corner node at each level */
void spiralLevelOrder(Node *root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty deque for doing spiral
    // level order traversal and enqueue root
    deque<Node*> q;
    q.push_front(root);
 
    // create a stack to store Binary Tree nodes
    // to insert into DLL later
    stack<Node*> stk;
 
    int level = 0;
    while (!q.empty())
    {
        // nodeCount indicates number of Nodes
        // at current level.
        int nodeCount = q.size();
 
        // Dequeue all Nodes of current level and
        // Enqueue all Nodes of next level
        if (level&1)    //odd level
        {
            while (nodeCount > 0)
            {
                // dequeue node from front & push it to
                // stack
                Node *node = q.front();
                q.pop_front();
                stk.push(node);
 
                // insert its left and right children
                // in the back of the deque
                if (node->left != NULL)
                    q.push_back(node->left);
                if (node->right != NULL)
                    q.push_back(node->right);
 
                nodeCount--;
            }
        }
        else    //even level
        {
            while (nodeCount > 0)
            {
                // dequeue node from the back & push it
                // to stack
                Node *node = q.back();
                q.pop_back();
                stk.push(node);
 
                // inserts its right and left children
                // in the front of the deque
                if (node->right != NULL)
                    q.push_front(node->right);
                if (node->left != NULL)
                    q.push_front(node->left);
                nodeCount--;
            }
        }
        level++;
    }
 
    // head pointer for DLL
    Node* head = NULL;
 
    // pop all nodes from stack and
    // push them in the beginning of the list
    while (!stk.empty())
    {
        push(&head, stk.top());
        stk.pop();
    }
 
    cout << "Created DLL is:\n";
    printList(head);
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
    // Let us create binary tree shown in above diagram
    Node *root =  newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    //root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    //root->right->right->right  = newNode(15);
 
    spiralLevelOrder(root);
 
    return 0;
}


