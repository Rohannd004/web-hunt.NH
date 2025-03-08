
#include<stdio.h>
#include<stdlib.h>

int main()
{

    FILE *file = fopen("sample.txt", "w");
    if(file == NULL) {
        printf("error opening file for writing. \n");
        return 1;
    }
    fprintf(file, "Hello World!\n");
    fprintf(file, "This is a simple file handling example in C. \n");
    fclose(file);
    printf("Data written to file successfully. \n");
    return 0;

}
