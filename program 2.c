#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Function to verify if a vehicle registration number is valid
bool verifyRegistration(char registration[])
{
// Check if the registration number has exactly 10 characters
if (strlen(registration) != 10)
{
return false;
}
// Check if the first two characters are alphabets (e.g., "KA" for Karnataka)
for (int i = 0; i < 2; i++)
{
if (!isalpha(registration[i]))
{
return false;
}
}
// Check if the next two characters are numbers (e.g., "09" for a specific district)
for (int i = 2; i < 4; i++)
{
if (!isdigit(registration[i]))
{
return false;
}
}
// Check if the next two characters are alphabets (e.g., "MN" for serial number)
for (int i = 4; i < 6; i++)
{
if (!isalpha(registration[i]))
{
return false;
}
}
// Check if the penultimate two characters are numbers (e.g., "3865" for vehicle number)
for (int i = 6; i < 10; i++)
{
if (!isdigit(registration[i]))
{
return false;
}
}
return true;
}
int main() {
char registration[11];
printf("Enter a vehicle registration number: ");
scanf("%s", registration);
if (verifyRegistration(registration))
{
printf("Accept: Vehicle registration number is valid.\n");
}
else
{
printf("Reject: Vehicle registration number is invalid.\n");
}
return 0;
}
