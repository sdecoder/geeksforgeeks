#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;
 
struct node
{
     int data;
     struct node* left;
     struct node* right;
};
 
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = node->right = NULL;
 
     return node;
}
 
/* root - root of the binary tree
vd - vertical distance diagonally
diagonalSum - map to store Diagonal Sum(Passed by Reference) */
 
void diagonalSumUtil(struct node* root, int vd, map<int, int> &diagonalSum)
{
     if(!root)
           return;
     diagonalSum[vd] += root->data;
 
     // increase the vertical distance if left child
     diagonalSumUtil(root->left, vd + 1, diagonalSum);
 
     // vertical distance remains same for right child
     diagonalSumUtil(root->right, vd, diagonalSum);
}
 
//Function to calculate diagonal sum of given binary tree
void diagonalSum(struct node* root)
 {
 
     map<int, int> diagonalSum; // create a map to store Diagonal Sum
     diagonalSumUtil(root, 0, diagonalSum);
 
     map<int, int>::iterator it;
     cout << "Diagonal sum in a binary tree is - ";
     for(it = diagonalSum.begin(); it != diagonalSum.end(); ++it) {
          cout << it->second << " ";
 }
}
 
int main()
{
     struct node* root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(9);
     root->left->right = newNode(6);
     root->right->left = newNode(4);
     root->right->right = newNode(5);
     root->right->left->right = newNode(7);
     root->right->left->left = newNode(12);
     root->left->right->left = newNode(11);
     root->left->left->right = newNode(10);
 
     diagonalSum(root);
 
    return 0;
}
//C++ implementation is contributed by Aditya Goel


