// A BST node to store future reservations
struct node {
  int time; // reservation time
  struct node* left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->time = item;
  temp->left = temp->right = NULL;
  return temp;
}

/* BST insert to process a new reservation request at
   a given time (future time).  This function does
   reservation only if there is no existing job within
   k time frame of new job  */
struct node* insert(struct node* root, int time, int k) {
  /* If the tree is empty, return a new node */
  if (root == NULL) return newNode(time);

  // Check if this job conflicts with existing
  // reservations
  if ((time - k < root->time) && (time + k > root->time)) return root;

  /* Otherwise, recur down the tree */
  if (time < root->time)
    root->left = insert(root->left, time, k);
  else
    root->right = insert(root->right, time, k);

  /* return the (unchanged) node pointer */
  return root;
}
