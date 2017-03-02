#include "project.h"

struct Books listOfBook;

void displayAuthor()
{
    int i, *whichBooks;
    char wish, authorLN[NAME_SIZE];

        //getc(stdin);
        printf("Give the last name of an author: ");
start:  fgets(authorLN, NAME_SIZE, stdin);
        trailingNL(authorLN);

    whichBooks = seqASearch(authorLN, &listOfBook);

    if (whichBooks[0] == -1){
        printf("\nThere is no such a name\n");
        printf("Do you want to return to menu?(y/n): ");
        wish = getchar();
        if (wish == 'y')
            return;
        else if (wish == 'n'){
            printf("\nGive a valid last name: ");
            getc(stdin);
            goto start;
        }
        else
            printf("\nerror: uknown command %c\n", wish);
    }
    for(i = 0;  i < numberOfBooks; i++)
        print(whichBooks[i]);

    numberOfBooks = 0;
}
