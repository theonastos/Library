#include "project.h"

//Sequential search for the id of books
//Returns the book of which the given id matches
int seqSearch(int key, struct Books *struct1){
    int i;

    for (i = 0; i < (*struct1).numOfBooks; i++)
        if (key == (*struct1).arr[i].id){
            return i;
        }
    return -1;
}

//Sequential search for the title of books
//Returns the book of which the given title matches
int seqTSearch(char *key, struct Books *struct1){
    int i;

    for (i = 0; i < (*struct1).numOfBooks; i++){
            if (strcmp(key, (*struct1).arr[i].title) == 0){
                return i;
        }
    }
    return -1;
}

//Sequential search for the authors
//Returns the books the given author participates
int *seqASearch(char *key, struct Books *struct1){
    int i, j = 0;
    int *whichBooks;

    whichBooks = (int *)malloc(sizeof(int));

    for (i = 0; i < (*struct1).numOfBooks; i++){
        for (j = 0; j < (*struct1).arr[i].numberOfAuthors; j++){
            if (strcmp(key, (*struct1).arr[i].authors[j].lastName) == 0){
                numberOfBooks++;
                whichBooks = (int *)realloc(whichBooks, sizeof(int) * numberOfBooks);
                whichBooks[numberOfBooks-1] = i;
            }
        }
    }
    if (numberOfBooks == 0){
        whichBooks[0] = -1;
        return whichBooks;
    }
    return whichBooks;

}
//Returns the number of digits an integer has
int numDigits(int number)
{
    int digits = 0;

    if (number < 0) digits = 1;
    else if (number == 0) digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}
//Removes the trailingNL of a String
void trailingNL(char *str)
{
size_t ln = strlen(str) - 1;
if (str[ln] == '\n')
    str[ln] = '\0';
}
//Swaps the position of two Books in the arr
void swapStructs(struct Book *struct1, struct Book *struct2){
    struct Book temp;

    temp = *struct1;
    *struct1 = *struct2;
    *struct2 = temp;
}
//Prints all elements of the ith book
void print(int i){
    int j = 0;
    printf("\n");
    printf("Book %d\n", i+1);
    printf("id:                %d\n", listOfBook.arr[i].id);
    printf("Title:             %s\n", listOfBook.arr[i].title);
    printf("Summary:           %s\n", listOfBook.arr[i].summary);
    printf("Num of authors:    %d\n", listOfBook.arr[i].numberOfAuthors);

    for(j = 0; j < listOfBook.arr[i].numberOfAuthors; j++){
        printf("Author %d:          %s\n", j+1, listOfBook.arr[i].authors[j].firstName);
        printf("                   %s\n", listOfBook.arr[i].authors[j].lastName);

    }
}
