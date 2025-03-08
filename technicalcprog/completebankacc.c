#include <stdio.h>
#include <string.h>

struct User {
    int id;
    char name[50];
    float balance;
};


void createUser(struct User users[], int *count);
void updateUser(struct User users[], int count);
void deleteUser(struct User users[], int *count);
void creditMoney(struct User users[], int count);
void debitMoney(struct User users[], int count);
void transferMoney(struct User users[], int count);

int main() {
    struct User users[100];
    int userCount = 0;
    int choice;

    while (1) {
        printf("\n select an option:\n");
        printf("1. Create User\n");
        printf("2. Update User\n");
        printf("3. Delete User\n");
        printf("4. Credit Money\n");
        printf("5. Debit Money\n");
        printf("6. Transfer Money\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser(users, &userCount);
                break;
            case 2:
                updateUser(users, userCount);
                break;
            case 3:
                deleteUser(users, &userCount);
                break;
            case 4:
                creditMoney(users, userCount);
                break;
            case 5:
                debitMoney(users, userCount);
                break;
            case 6:
                transferMoney(users, userCount);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void createUser(struct User users[], int *count) {
    printf("Enter user ID: ");
    scanf("%d", &users[*count].id);
    printf("Enter user name: ");
    scanf("%s", users[*count].name);
    printf("Enter initial balance: ");
    scanf("%f", &users[*count].balance);
    (*count)++;
    printf("User created successfully!\n");
}

void updateUser(struct User users[], int count) {
    int id, i;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (users[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", users[i].name);
            printf("Enter new balance: ");
            scanf("%f", &users[i].balance);
            printf("User updated successfully!\n");
            return;
        }
    }
    printf("User not found.\n");
}

void deleteUser(struct User users[], int *count) {
    int id, i, j;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *count; i++) {
        if (users[i].id == id) {
            for (j = i; j < (*count) - 1; j++) {
                users[j] = users[j + 1];
            }
            (*count)--;
            printf("User deleted successfully!\n");
            return;
        }
    }
    printf("User not found.\n");
}

void creditMoney(struct User users[], int count) {
    int id, i;
    float amount;
    printf("Enter user ID to credit money: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (users[i].id == id) {
            printf("Enter amount to credit: ");
            scanf("%f", &amount);
            users[i].balance += amount;
            printf("Amount credited successfully! New balance: %.2f\n", users[i].balance);
            return;
        }
    }
    printf("User not found.\n");
}

void debitMoney(struct User users[], int count) {
    int id, i;
    float amount;
    printf("Enter user ID to debit money: ");
    scanf("%d", &id);
    for (i = 0; i < count; i++) {
        if (users[i].id == id) {
            printf("Enter amount to debit: ");
            scanf("%f", &amount);
            if (amount <= users[i].balance) {
                users[i].balance -= amount;
                printf("Amount debited successfully! New balance: %.2f\n", users[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("User not found.\n");
}

void transferMoney(struct User users[], int count) {
    int senderId, receiverId, i, j;
    float amount;
    printf("Enter sender ID: ");
    scanf("%d", &senderId);
    printf("Enter receiver ID: ");
    scanf("%d", &receiverId);
    for (i = 0; i < count; i++) {
        if (users[i].id == senderId) {
            for (j = 0; j < count; j++) {
                if (users[j].id == receiverId) {
                    printf("Enter amount to transfer: ");
                    scanf("%f", &amount);
                    if (amount <= users[i].balance) {
                        users[i].balance -= amount;
                        users[j].balance += amount;
                        printf("Amount transferred successfully!\n");
                    } else {
                        printf("Insufficient balance.\n");
                    }
                    return;
                }
            }
            printf("Receiver not found.\n");
            return;
        }
    }
    printf("Sender not found.\n");
}
