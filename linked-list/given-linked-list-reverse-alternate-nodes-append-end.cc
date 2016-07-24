#include <stdio.h>
#include <stdlib.h>

/* A linked list node */
struct node {
  int data;
  struct node* next;
};

/* Function to reverse all even positioned node and append at the end
   odd is the head node of given linked list */
void rearrange(struct node* odd) {
  // If linked list has less than 3 nodes, no change is required
  if (odd == NULL || odd->next == NULL || odd->next->next == NULL) return;

  // even points to the beginning of even list
  struct node* even = odd->next;

  // Remove the first even node
  odd->next = odd->next->next;

  // odd points to next node in odd list
  odd = odd->next;

  // Set terminator for even list
  even->next = NULL;

  // Traverse the  list
  while (odd && odd->next) {
    // Store the next node in odd list
    struct node* temp = odd->next->next;

    // Link the next even node at the beginning of even list
    odd->next->next = even;
    even = odd->next;

    // Remove the even node from middle
    odd->next = temp;

    // Move odd to the next odd node
    if (temp != NULL) odd = temp;
  }

  // Append the even list at the end of odd list
  odd->next = even;
}

/* Function to add a node at the beginning of Linked List */
void push(struct node** head_ref, int new_data) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}

/* Druver program to test above function */
int main() {
  struct node* start = NULL;

  /* The constructed linked list is:
   1->2->3->4->5->6->7 */
  push(&start, 7);
  push(&start, 6);
  push(&start, 5);
  push(&start, 4);
  push(&start, 3);
  push(&start, 2);
  push(&start, 1);

  printf("\n Linked list before calling  rearrange() ");
  printList(start);

  rearrange(start);

  printf("\n Linked list after calling  rearrange() ");
  printList(start);

  return 0;
}
