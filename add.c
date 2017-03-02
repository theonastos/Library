#include "project.h"

struct Books listOfBook;

void add(void)
{
    int i, j;

    if (didLoad == 0){
        free(listOfBook.arr);
        listOfBook.arr = (struct Book *)malloc(sizeof(struct Book));
        if (listOfBook.arr == NULL) exit (1);
        listOfBook.numOfBooks = 1;
        didLoad = 1;
    }
    else{
        listOfBook.numOfBooks++;
        listOfBook.arr = (struct Book *)realloc(listOfBook.arr, sizeof(struct Book) * listOfBook.numOfBooks);
    }

    i = listOfBook.numOfBooks -1;

    listOfBook.arr[i].id = 100 + listOfBook.numOfBooks;

    printf("Give title: ");
    fgets(listOfBook.arr[i].title, TITLE_SIZE, stdin);
    trailingNL(listOfBook.arr[i].title);

    printf("Give summary: ");
    fgets(listOfBook.arr[i].summary, SUMMARY_SIZE, stdin);
    trailingNL(listOfBook.arr[i].summary);

    printf("Give number of authors: ");
    scanf("%d", &listOfBook.arr[i].numberOfAuthors);
    getc(stdin);

    listOfBook.arr[i].authors = (struct Author *)malloc(sizeof(struct Author) * listOfBook.arr[i].numberOfAuthors);

    for(j = 0; j < listOfBook.arr[i].numberOfAuthors; j++){
            printf("Give fn of author %d: ", j+1);
            fgets(listOfBook.arr[i].authors[j].firstName, NAME_SIZE, stdin);
            trailingNL(listOfBook.arr[i].authors[j].firstName);

            printf("Give ln of author %d: ", j+1);
            fgets(listOfBook.arr[i].authors[j].lastName, NAME_SIZE, stdin);
            trailingNL(listOfBook.arr[i].authors[j].lastName);
            }
}
