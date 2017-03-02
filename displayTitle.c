#include "project.h"

struct Books listOfBook;

void displayTitle(void){

    int i;
    char wish;
    char title[TITLE_SIZE];

        printf("Give a title of a Book: ");
start:  fgets(title, TITLE_SIZE, stdin);
        trailingNL(title);

    if((i = seqTSearch(title, &listOfBook)) == -1){
        printf("\nThere is no such a title: %s\n", title);
        printf("Do you want to return to menu?(y/n): ");
        wish = getchar();
        if (wish == 'y')
            return;
        else if (wish == 'n'){
            printf("\nGive a valid title: ");
            getc(stdin);
            goto start;
        }
        else
            printf("\nerror: uknown command %c\n", wish);
        }
    print(i);
}
