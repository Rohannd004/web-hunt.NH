
#include <stdio.h>
int main()
{
    int pass;
    while(1)
    {
        printf("\nEnter the password: ");
        scanf("%d",&pass);
        if(pass==1234)
        {
            printf("CORRECT PASSWORD");
            break;
        }
        else
        {
            printf("INCORRECT PASSWORD,TRY AGAIN..");
            continue;
        }
    }
    return 0;
}
