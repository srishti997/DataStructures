#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_URL_LENGTH 100
// Structure for a node in the stack
typedef struct Node {
char url[MAX_URL_LENGTH];
struct Node* next;
} Node;
// Structure for the stack
typedef struct {
Node* top;
} Stack;
// Function to initialize an empty stack
void initialize(Stack* stack) {
stack->top = NULL;
}
// Function to push a URL onto the stack
void push(Stack* stack, const char* url) {
Node* newNode = (Node*)malloc(sizeof(Node));
if (newNode == NULL) {
printf("Memory allocation failed.\n");
return;
}
strncpy(newNode->url, url, MAX_URL_LENGTH);
newNode->next = stack->top;
stack->top = newNode;
}
// Function to pop a URL from the stack
void pop(Stack* stack) {
if (stack->top == NULL) {
printf("No more URLs in the history.\n");
return;
}
Node* temp = stack->top;
stack->top = stack->top->next;
free(temp);
}
// Function to display the current URL
void displayCurrentURL(Stack* stack) {
if (stack->top == NULL) {
printf("No URL currently loaded.\n");
} else {
printf("Current URL: %s\n", stack->top->url);
}
}
int main() {
Stack historyStack;
initialize(&historyStack);
int choice;
char url[MAX_URL_LENGTH];
while (1) {
printf("\nMenu:\n");
printf("1. Visit a URL\n");
printf("2. Go Back\n");
printf("3. Display Current URL\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter URL to visit: ");
scanf("%s", url);
push(&historyStack, url);
break;
case 2:
pop(&historyStack);
break;
case 3:
displayCurrentURL(&historyStack);
break;
case 4:
// Clean up and exit the program
while (historyStack.top != NULL) {
pop(&historyStack);
}
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
