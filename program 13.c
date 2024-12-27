#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure to represent an item in the shopping cart
struct CartItem
{
char name[100];
float price;
int quantity;
struct CartItem* next;
struct CartItem* prev;
};
// Structure to represent the shopping cart
struct ShoppingCart
{
struct CartItem* head;
struct CartItem* tail;
};
// Function to initialize an empty shopping cart
void initializeCart(struct ShoppingCart* cart)
{
cart->head = NULL;
cart->tail = NULL;
}
// Function to add items to the cart
void addItem(struct ShoppingCart* cart, const char* name, float price, int quantity)
{
struct CartItem* newItem = (struct CartItem*)malloc(sizeof(struct CartItem));
strncpy(newItem->name, name, sizeof(newItem->name));
newItem->price = price;
newItem->quantity = quantity;
newItem->next = NULL;
newItem->prev = cart->tail;
if (cart->tail != NULL)
{
cart->tail->next = newItem;
}
cart->tail = newItem;
if (cart->head == NULL)
{
cart->head = newItem;
}
}
// Function to remove items from the cart by name
void removeItem(struct ShoppingCart* cart, const char* name)
{
struct CartItem* current = cart->head;
while (current != NULL)
{
if (strcmp(current->name, name) == 0)
{
if (current->prev != NULL)
{
current->prev->next = current->next;
}
else
{
cart->head = current->next;
}
if (current->next != NULL)
{
current->next->prev = current->prev;
}
else
{
cart->tail = current->prev;
}
free(current);
return;
}
current = current->next;
}
printf("Item '%s' not found in the cart.\n", name);
}
// Function to display the cart in forward direction
void displayCartForward(struct ShoppingCart* cart)
{
struct CartItem* current = cart->head;
printf("Shopping Cart:\n");
while (current != NULL)
{
printf("Name: %s, Price: $%.2f, Quantity: %d, Total Cost: $%.2f\n", current->name,
current->price, current->quantity, current->price * current->quantity);
current = current->next;
}
printf("\n");
}
// Function to calculate and display the total cost of items in the cart
void displayTotalCost(struct ShoppingCart* cart)
{
struct CartItem* current = cart->head;
float totalCost = 0.0;
while (current != NULL)
{
totalCost += (current->price * current->quantity);
current = current->next;
}
printf("Total Cost of Items in the Cart: $%.2f\n", totalCost);
}
int main()
{
struct ShoppingCart myCart;
initializeCart(&myCart);
// Add items to the cart
addItem(&myCart, "Product A", 10.99, 2);
addItem(&myCart, "Product B", 5.49, 3);
addItem(&myCart, "Product C", 2.99, 1);
// Display the cart
displayCartForward(&myCart);
// Remove an item from the cart
removeItem(&myCart, "Product B");
// Display the updated cart
displayCartForward(&myCart);
// Calculate and display the total cost
displayTotalCost(&myCart);
return 0;
}
