#include <stdio.h>
#include <stdlib.h>
// Structure to represent a customer
struct Customer
{
char name[50];
int age;
int numTickets;
struct Customer* next;
};
// Structure to represent the queue
struct Queue
{
struct Customer* front;
struct Customer* rear;
};
// Initialize a queue
struct Queue* createQueue()
{
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
queue->front = queue->rear = NULL;
return queue;
}
// Check if the queue is empty
int isEmpty(struct Queue* queue)
{
return (queue->front == NULL);
}
// Add a customer to the rear of the queue
void enqueue(struct Queue* queue, struct Customer customer)
{
struct Customer* newNode = (struct Customer*)malloc(sizeof(struct Customer));
newNode->next = NULL;
if (isEmpty(queue)) {
queue->front = queue->rear = newNode;
} else {
queue->rear->next = newNode;
queue->rear = newNode;
}
}
// Remove and return a customer from the front of the queue
struct Customer dequeue(struct Queue* queue)
{
struct Customer emptyCustomer = {"", 0, 0, NULL};
if (isEmpty(queue))
{
return emptyCustomer; // Queue is empty
}
struct Customer* temp = queue->front;
struct Customer customer = *temp;
queue->front = queue->front->next;
free(temp);
return customer;
}
int main()
{
// Total number of tickets available
int totalTickets = 100;
struct Queue* ticketQueue = createQueue();
while (totalTickets > 0)
{
struct Customer customer;
printf("Enter customer name: ");
scanf("%s", customer.name);
printf("Enter customer age: ");
scanf("%d", &customer.age);
printf("Enter number of tickets needed: ");
scanf("%d", &customer.numTickets);
if (customer.numTickets <= totalTickets)
{
totalTickets -= customer.numTickets;
enqueue(ticketQueue, customer);
printf("Tickets sold to %s (%d tickets remaining)\n", customer.name, totalTickets);
}
else
{
printf("Insufficient tickets available. Tickets not sold to %s\n", customer.name);
}
printf("Do you want to add another customer? (1 for yes, 0 for no): ");
int choice;
scanf("%d", &choice);
if (choice != 1)
{
break;
}
}
printf("Houseful! All tickets are sold.\n");
return 0;
}
