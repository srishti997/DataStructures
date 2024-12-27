#include <stdio.h>
int main()
{
int n;
printf("Enter the size of the array:");
scanf("%d",&n);
int arr[n];
printf("Enter the %d values to store it in array: \n", n);
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("The values stored in the array are: \n");
for(int i=0;i<n;i++)
{
printf("%d \n",arr[i]);
}
}
