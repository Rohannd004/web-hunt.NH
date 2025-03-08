#include<stdio.h>

#define MAX_USERS 3

struct User {
    int id;
    char name[100];
    int balance;
};

int main() {
    struct User users[MAX_USERS];
    for(int i = 0; i < MAX_USERS; i++) {
        printf("enter the id: ");
        scanf("%d",&users[i].id);
        printf("enter the name: ");
        scanf("%s",&users[i].name);
        printf("enter the balance: ");
        scanf("%d",&users[i].balance);


    }
    for(int i = 0; i < MAX_USERS; i++) {
        printf("%d", users[i].id);
        printf("%s", users[i].name);
        printf("%d", users[i].balance);
    }
    int find,i;
    printf("enter the UserID to check the balance: ");
    scanf("%d", &find);

    for(i = 0; i < MAX_USERS; i++) {
            if(find==users[i].id) {
                printf("balance of the user %d ; %d",find,users[i].balance);
            }
}
}