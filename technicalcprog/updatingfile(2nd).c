#include<stdio.h>
#include<stdlib.h>
 int main()
 {

     FILE *file = fopen("example.txt", "a");
     if(file == NULL) {
        printf("Error opening file for reading and writing. \n");
        return 1;
     }
     //fseek(file, 0, SEEK_SET);//
     fprintf(file, "updated content: Hello,updated world!\n");
     fclose(file);
     printf("data updated in file successsfully.\n");
     return 0;

 }