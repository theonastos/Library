#include "project.h"

struct Books listOfBook;

void save(char **argv)
{
    int i,j;

    FILE *file = fopen(argv[1], "w");

    fprintf(file, "There are %d Books\n\n", listOfBook.numOfBooks);

    for(i = 0; i < listOfBook.numOfBooks; i++){

        fprintf(file, "Book %d\n", i+1);
        fprintf(file, "id:                %d\n", listOfBook.arr[i].id);
        fprintf(file, "Title:             %s\n", listOfBook.arr[i].title);
        fprintf(file, "Summary:           %s\n", listOfBook.arr[i].summary);
        fprintf(file, "Num of authors:    %d\n", listOfBook.arr[i].numberOfAuthors);

        for(j = 0; j < listOfBook.arr[i].numberOfAuthors; j++){
            fprintf(file, "Author:            %s\n", listOfBook.arr[i].authors[j].firstName);
            fprintf(file, "                   %s\n", listOfBook.arr[i].authors[j].lastName);
        }
        fprintf(file, "\n");
    }
    printf("Saved to file successfully\n");
    fclose( file );
}
