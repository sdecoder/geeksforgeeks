// Program to merge two sorted linked lists without
// using any extra space and without changing links
// of first list
#include <bits/stdc++.h>
using namespace std;
 
 /* Structure for a linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Given a reference (pointer to pointer) to the head
  of a list and an int, push a new node on the front
  of the list. */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
// Function to merge two sorted linked lists
// LL1 and LL2 without using any extra space.
void mergeLists(struct node *a, struct node * &b)
{
    // run till either one of a or b runs out
    while (a && b)
    {
        // for each element of LL1,
        // compare it with first element of LL2.
        if (a->data > b->data)
        {
            // swap the two elements involved
            // if LL1 has a greater element
            swap(a->data, b->data);
 
            struct node *temp = b;
 
            // To keep LL2 sorted, place first
            // element of LL2 at its correct place
            if (b->next && b->data > b->next->data)
            {
                b = b->next;
                struct node *ptr= b, *prev = NULL;
 
                // find mismatch by traversing the
                // second linked list once
                while (ptr && ptr->data < temp->data)
                {
                    prev = ptr;
                    ptr = ptr -> next;
                }
 
                // correct the pointers
                prev->next = temp;
                temp->next = ptr;
            }
        }
 
        // move LL1 pointer to next element
        a = a->next;
    }
}
 
// Code to print the linked link
void printList(struct node *head)
{
    while (head)
    {
        cout << head->data << "->" ;
        head = head->next;
    }
    cout << "NULL" << endl;
}
 
// Driver code
int main()
{
    struct node *a = NULL;
    push(&a, 10);
    push(&a, 8);
    push(&a, 7);
    push(&a, 4);
    push(&a, 2);
 
    struct node *b = NULL;
    push(&b, 12);
    push(&b, 3);
    push(&b, 1);
 
    mergeLists(a, b);
 
    cout << "First List: ";
    printList(a);
 
    cout << "Second List: ";
    printList(b);
 
    return 0;
}



