#include <stdio.h>
#include <stdlib.h>
// Structure to represent a node in the BST
struct Node
{
int data;
struct Node* left;
struct Node* right;
};
// Function to initialize an empty BST
struct Node* initializeBST()
{
return NULL;
}
// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value)
{
if (root == NULL)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->left = newNode->right = NULL;
return newNode;
}
if (value < root->data)
{
root->left = insertNode(root->left, value);
}
else if (value > root->data)
{
root->right = insertNode(root->right, value);
}
return root;
}
// Function to find the minimum value in the BST
int findMinimum(struct Node* root)
{
if (root == NULL)
{
printf("The BST is empty.\n");
return -1;
}
while (root->left != NULL)
{
root = root->left;
}
return root->data;
}
// Function to find the maximum value in the BST
int findMaximum(struct Node* root)
{
if (root == NULL)
{
printf("The BST is empty.\n");
return -1;
}
while (root->right != NULL)
{
root = root->right;
}
return root->data;
}
// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int value)
{
if (root == NULL)
{
printf("Value %d not found in the BST.\n", value);
return root;
}
if (value < root->data)
{
root->left = deleteNode(root->left, value);
}
else if (value > root->data)
{
root->right = deleteNode(root->right, value);
}
else
{
if (root->left == NULL)
{
struct Node* temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
struct Node* temp = root->left;
free(root);
return temp;
}
struct Node* temp = root->right;
while (temp->left != NULL)
{
temp = temp->left;
}
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}
// Function to display the BST in inorder traversal
void displayInorder(struct Node* root)
{
if (root == NULL)
{
return;
}
displayInorder(root->left);
printf("%d ", root->data);
displayInorder(root->right);
}
int main()
{
struct Node* root = initializeBST();
while (1)
{
printf("\nBinary Search Tree Menu:\n");
printf("1. Insert a node\n");
printf("2. Delete a node\n");
printf("3. Find Minimum\n");
printf("4. Find Maximum\n");
printf("5. Display Inorder Traversal\n");
printf("6. Exit\n");
int choice, value;
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
root = insertNode(root, value);
break;
case 2:
printf("Enter value to delete: ");
scanf("%d", &value);
root = deleteNode(root, value);
break;
case 3:
printf("Minimum value: %d\n", findMinimum(root));
break;
case 4:
printf("Maximum value: %d\n", findMaximum(root));
break;
case 5:
printf("Inorder Traversal: ");
displayInorder(root);
printf("\n");
break;
case 6:
exit(0);
default:
printf("Invalid choice. Try again.\n");
break;
}
}
return 0;
}
