#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *ROOT = NULL;

struct Node *insertNode(struct Node *, int);
struct Node *minValueNode(struct Node *);
struct Node *deleteNode(struct Node *, int);
void traversePreOrder(struct Node *);
void traversePostOrder(struct Node *);
void traverseInOrder(struct Node *);
int getValue(char[]);

int main() {

  int choice;

  printf("Menu:\n"
         " 1. Insert\n"
         " 2. Preorder traversal\n"
         " 3. Inorder traversal\n"
         " 4. Postorder traversal\n"
         " 5. Delete\n"
         " 6. Exit");

  while (true) {

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1:
      insertNode(ROOT, getValue("Enter the value: "));
      break;
    case 2:
      printf("PreOrder: ");
      traversePreOrder(ROOT);
      break;
    case 3:
      printf("InOrder: ");
      traverseInOrder(ROOT);
      break;
    case 4:
      printf("PostOrder: ");
      traversePostOrder(ROOT);
      break;
    case 5:
      deleteNode(ROOT, getValue("Value to delete: "));
      break;
    case 6:
      printf("Exiting...\n");
      return 0;
    default:
      printf("\nInvalid choice\n");
    }
  }

  return 0;
}

struct Node *minValueNode(struct Node *node) {

  struct Node *current = node;

  while (current != NULL && current->left != NULL)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *node, int val) {

  if (node == NULL)
    return node;

  if (val < node->data)
    node->left = deleteNode(node->left, val);

  else if (val > node->data)
    node->right = deleteNode(node->right, val);

  else {

    if (node->left == NULL) {

      struct Node *temp = node->right;
      free(node);

      return temp;

    } else if (node->right == NULL) {

      struct Node *temp = node->left;
      free(node);

      return temp;
    }

    struct Node *temp = minValueNode(node->right);
    node->data = temp->data;
    node->right = deleteNode(node->right, temp->data);
  }

  return node;
}

struct Node *insertNode(struct Node *node, int key) {

  if (node == NULL) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));

    newNode->left = newNode->right = NULL;

    newNode->data = key;

    if (ROOT == NULL)
      ROOT = newNode;

    return newNode;

  } else {
    if (key < node->data)
      node->left = insertNode(node->left, key);
    else if (key > node->data)
      node->right = insertNode(node->right, key);
  }

  return node;
}

void traversePreOrder(struct Node *node) {

  if (node == NULL)
    return;

  printf("%d -> ", node->data);

  traversePreOrder(node->left);

  traversePreOrder(node->right);
}

void traversePostOrder(struct Node *node) {

  if (node == NULL)
    return;

  traversePostOrder(node->left);

  traversePostOrder(node->right);

  printf("%d -> ", node->data);
}

void traverseInOrder(struct Node *node) {

  if (node == NULL)
    return;

  traverseInOrder(node->left);

  printf("%d -> ", node->data);

  traverseInOrder(node->right);
}

int getValue(char s[]) {
  int n;
  printf("%s", s);
  scanf("%d", &n);
  return n;
}
