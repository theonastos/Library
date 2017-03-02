#include "project.h"

struct Books listOfBook;
void swapStructs(struct Book *struct1, struct Book *struct2);

void my_delete(void)
{
    int id, i;
    char wish;

		printf("Give the id of the book you want to delete: ");
start:  scanf("%d", &id);

    while((i = seqSearch(id, &listOfBook)) == -1){
        printf("\nThere is no such id: %d\n", id);
        printf("Do you want to return to menu?(y/n): ");
        getc(stdin);
        wish = getchar();
        if (wish == 'y')
            return;
        else if (wish == 'n'){
            printf("\nGive a valid id: ");
            getc(stdin);
            goto start;
        }
        else
            printf("\nerror: uknown command %c\n", wish);
        }
    

    if(listOfBook.arr[listOfBook.numOfBooks-1].id == id){
        listOfBook.arr = (struct Book *)realloc(listOfBook.arr, sizeof(struct Book) * --listOfBook.numOfBooks);
    }
    else{
        listOfBook.arr[listOfBook.numOfBooks-1].id = id;
        swapStructs(&listOfBook.arr[listOfBook.numOfBooks-1], &listOfBook.arr[i]);
        listOfBook.arr = (struct Book *)realloc(listOfBook.arr, sizeof(struct Book) * --listOfBook.numOfBooks);
    }
    printf("Deleted book successfully\n");
}
