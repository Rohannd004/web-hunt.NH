#include <stdio.h>
#include <stdlib.h>
char alp() {
   int x;
   printf("Enter the integer: ");
   scanf("%d", &x);
  return x;
int main() {
   printf("%c", alp()); // Call the alp function and print the result as a character
   return 0;
}