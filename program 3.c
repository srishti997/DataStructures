#include <stdio.h>
int main() {
int m, n, p, q;
printf("Enter the number of rows and columns of the first matrix: ");
scanf("%d %d", &m, &n);
printf("Enter the number of rows and columns of the second matrix: ");
scanf("%d %d", &p, &q);
if (n != p) {
printf("Matrix multiplication is not possible. Column of the first matrix must be equal to the row of the second matrix.\n");
return 1;
}
int firstMatrix[m][n], secondMatrix[p][q], resultMatrix[m][q];
printf("Enter elements of the first matrix:\n");
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
scanf("%d", &firstMatrix[i][j]);
}
}
printf("Enter elements of the second matrix:\n");
for (int i = 0; i < p; i++) {
for (int j = 0; j < q; j++) {
scanf("%d", &secondMatrix[i][j]);
}
}
// Matrix multiplication
for (int i = 0; i < m; i++) {
for (int j = 0; j < q; j++) {
resultMatrix[i][j] = 0;
for (int k = 0; k < n; k++) {
resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
}
}
}
printf("Resultant matrix after multiplication:\n");
for (int i = 0; i < m; i++) {
for (int j = 0; j < q; j++) {
printf("%d ", resultMatrix[i][j]);
}
printf("\n");
}
return 0;
}
