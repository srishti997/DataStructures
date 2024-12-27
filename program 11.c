#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the linked list
struct ListNode {
int val;
struct ListNode* next;
};
// Function to swap every two adjacent nodes in the linked list
struct ListNode* swapPairs(struct ListNode* head) {
// Check if the list is empty or has only one node
if (head == NULL || head->next == NULL) {
return head;
}
// Initialize pointers for swapping
struct ListNode* prev = NULL;
struct ListNode* current = head;
struct ListNode* nextNode = head->next;
// Update the head to the second node
head = nextNode;
// Perform swaps in pairs
while (current != NULL && nextNode != NULL) {
// Adjust pointers for swapping
current->next = nextNode->next;
nextNode->next = current;
if (prev != NULL) {
// Connect the previous pair to the current pair
prev->next = nextNode;
}
// Move to the next pair
prev = current;
current = current->next;
if (current != NULL) {
nextNode = current->next;
}
}
return head;
}
// Function to print the linked list
void printList(struct ListNode* head) {
struct ListNode* current = head;
while (current != NULL) {
printf("%d -> ", current->val);
current = current->next;
}
printf("NULL\n");
}
// Function to create a new node with a given value
struct ListNode* newNode(int value) {
struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
if (node != NULL) {
node->val = value;
node->next = NULL;
}
return node;
}
int main() {
// Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
struct ListNode* head = newNode(1);
head->next = newNode(2);
head->next->next = newNode(3);
head->next->next->next = newNode(4);
head->next->next->next->next = newNode(5);
printf("Original Linked List: ");
printList(head);
// Swap adjacent nodes
head = swapPairs(head);
printf("Modified Linked List: ");
printList(head);
// Clean up memory
while (head != NULL) {
struct ListNode* temp = head;
head = head->next;
free(temp);
}
return 0;
}
