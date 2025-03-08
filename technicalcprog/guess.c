#include <stdio.h>
void guess()
{
    int guess,num = 10;
    while(1) {
    printf("enter the number:");
    scanf("%d",&guess);
    if(num==guess)
    {
        printf("correct");
    } else {
        printf("incorrect \n");
    }
}
}
void main() {
    guess();
}