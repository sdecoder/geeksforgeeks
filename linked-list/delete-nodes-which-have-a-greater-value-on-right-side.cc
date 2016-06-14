#include <stdio.h>
#include <stdlib.h>
 
/* structure of a linked list node */
struct node
{
     int data;
     struct node *next;
};
 
/* prototype for utility functions */
void reverseList(struct node **headref);
void _delLesserNodes(struct node *head);
 
/* Deletes nodes which have a node with greater value node
  on left side */
void delLesserNodes(struct node **head_ref)
{
    /* 1) Reverse the linked list */
    reverseList(head_ref);
 
    /* 2) In the reversed list, delete nodes which have a node
       with greater value node on left side. Note that head
       node is never deleted because it is the leftmost node.*/
    _delLesserNodes(*head_ref);
 
    /* 3) Reverse the linked list again to retain the
       original order */
    reverseList(head_ref);
}
 
/* Deletes nodes which have greater value node(s) on left side */
void _delLesserNodes(struct node *head)
{
     struct node *current = head;
 
     /* Initialize max */
     struct node *maxnode = head;
     struct node *temp;
 
     while (current != NULL && current->next != NULL)
     {
         /* If current is smaller than max, then delete current */
         if(current->next->data < maxnode->data)
         {
             temp = current->next;
             current->next = temp->next;
             free(temp);
         }
 
         /* If current is greater than max, then update max and
            move current */
         else
         {
             current = current->next;
             maxnode = current;
         }
     }
}
 
/* Utility function to insert a node at the begining */
void push(struct node **head_ref, int new_data)
{
     struct node *new_node =
              (struct node *)malloc(sizeof(struct node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}
 
/* Utility function to reverse a linked list */
void reverseList(struct node **headref)
{
     struct node *current = *headref;
     struct node *prev = NULL;
     struct node *next;
     while (current != NULL)
     {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     *headref = prev;
}
 
/* Utility function to print a linked list */
void printList(struct node *head)
{
     while (head != NULL)
     {
        printf("%d ", head->data);
        head=head->next;
     }
     printf("\n");
}
 
/* Driver program to test above functions */
int main()
{
    struct node *head = NULL;
 
    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);
 
    printf("Given Linked List \n");
    printList(head);
 
    delLesserNodes(&head);
 
    printf("Modified Linked List \n");
    printList(head);
 
     return 0;
}
