#include <stdio.h>
#include <stdlib.h>
// Define the structure for a queue node
struct QueueNode {
int data;
struct QueueNode* next;
};
// Define the circular queue structure
struct CircularQueue {
struct QueueNode* front;
struct QueueNode* rear;
};
// Function to create an empty circular queue
struct CircularQueue* createCircularQueue() {
struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct
CircularQueue));
if (queue == NULL) {
printf("Memory allocation failed.\n");
return NULL;
}
queue->front = NULL;
queue->rear = NULL;
return queue;
}
// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
return (queue->front == NULL);
}
// Function to enqueue an element into the circular queue
void enqueue(struct CircularQueue* queue, int value) {
struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
if (newNode == NULL) {
printf("Memory allocation failed.\n");
return;
}
newNode->data = value;
newNode->next = NULL;
if (isEmpty(queue)) {
// If the queue is empty, set both front and rear to the new node
queue->front = newNode;
queue->rear = newNode;
newNode->next = newNode; // Circular link to itself
} else {
// Link the new node to the rear and update the rear
newNode->next = queue->front; // Circular link
queue->rear->next = newNode;
queue->rear = newNode;
}
}
// Function to dequeue an element from the circular queue
int dequeue(struct CircularQueue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty. Cannot dequeue.\n");
return -1; // Return a sentinel value for an empty queue
}
int removedValue;
struct QueueNode* temp = queue->front;
if (queue->front == queue->rear) {
// If there is only one element in the queue
removedValue = temp->data;
queue->front = NULL;
queue->rear = NULL;
free(temp);
} else {
// Remove and update the front of the queue
removedValue = temp->data;
queue->front = temp->next;
queue->rear->next = queue->front; // Circular link
free(temp);
}
return removedValue;
}
// Function to display the elements in the circular queue
void displayQueue(struct CircularQueue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty.\n");
return;
}
struct QueueNode* current = queue->front;
printf("Circular Queue: ");
do {
printf("%d -> ", current->data);
current = current->next;
} while (current != queue->front);
printf(" (front)\n");
}
int main() {
struct CircularQueue* queue = createCircularQueue();
int choice, value;
while (1) {
printf("\nMenu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display Queue\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter a value to enqueue: ");
scanf("%d", &value);
enqueue(queue, value);
break;
case 2:
value = dequeue(queue);
if (value != -1) {
printf("Dequeued value: %d\n", value);
}
break;
case 3:
displayQueue(queue);
break;
case 4:
// Clean up and exit
while (!isEmpty(queue)) {
dequeue(queue);
}
free(queue);
return 0;
default:
printf("Invalid choice. Please try again.\n");
}
}
return 0;
}
