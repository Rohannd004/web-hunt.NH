
#include <stdio.h>
#include <stdlib.h>

void addItem(FILE *file) {
    char item[100];

    printf("Enter the grocery item: ");
    getchar();
    fgets(item, sizeof(item), stdin);


    item[strcspn(item, "\n")] = '\0';


    fprintf(file, "%s\n", item);
    printf("Item added to the grocery list.\n");
}

void listItems(FILE *file) {
    char item[100];

    printf("\nGrocery List:\n");
    fseek(file, 0, SEEK_SET);


    while (fgets(item, sizeof(item), file) != NULL) {

        item[strcspn(item, "\n")] = '\0';
        printf("- %s\n", item);
    }
}

int main() {
    FILE *file;
    int choice;


    file = fopen("grocery_list.txt", "a+");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    do {

        printf("\nGrocery List Program\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(file);
                break;
            case 2:
                listItems(file);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);


    fclose(file);
    return 0;
}
