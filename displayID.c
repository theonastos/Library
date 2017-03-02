#include "project.h"

struct Books listOfBook;

void displayID(void){

    int id, i;
    char wish;

        printf("Give an id: ");
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
    print(i);
}
