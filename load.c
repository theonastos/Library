#include "project.h"

#define tagLength 19

struct Books listOfBook;
int numDigits(int number);

void load(char **argv)
{
    int i, j;

    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Could not open file\n");
	return;
    }
    didLoad = 1;

    fseek(file, 10, SEEK_SET);
    fscanf(file, "%d", &listOfBook.numOfBooks);

    free(listOfBook.arr);
    listOfBook.arr = (struct Book *)malloc(sizeof(struct Book) * listOfBook.numOfBooks);

    for(i = 0; i < listOfBook.numOfBooks; i++){

        if (i == 0) fseek(file, 18 + tagLength, SEEK_CUR);
        else fseek (file, 8 + numDigits(i+1), SEEK_CUR);

        fscanf(file, "%d", &listOfBook.arr[i].id);
        fseek(file, tagLength + 2, SEEK_CUR);

        fgets(listOfBook.arr[i].title, TITLE_SIZE, file);
        trailingNL(listOfBook.arr[i].title);
        fseek(file, tagLength, SEEK_CUR);

        fgets(listOfBook.arr[i].summary, SUMMARY_SIZE, file);
        trailingNL(listOfBook.arr[i].summary);
        fseek(file, tagLength, SEEK_CUR);

        fscanf(file, "%d", &listOfBook.arr[i].numberOfAuthors);
        fseek(file, tagLength + 2, SEEK_CUR);

        listOfBook.arr[i].authors = (struct Author *)malloc(sizeof(struct Author) * listOfBook.arr[i].numberOfAuthors);

        for (j = 0; j < listOfBook.arr[i].numberOfAuthors; j++){
                fgets(listOfBook.arr[i].authors[j].firstName, NAME_SIZE, file);
                trailingNL(listOfBook.arr[i].authors[j].firstName);
                fseek(file, tagLength, SEEK_CUR);

                fgets(listOfBook.arr[i].authors[j].lastName, NAME_SIZE, file);
                trailingNL(listOfBook.arr[i].authors[j].lastName);
                fseek(file, tagLength, SEEK_CUR);
        }
    }
	if(listOfBook.numOfBooks == 0){
		printf("There are no books to load\n");
		didLoad = 0;
	}
	else
		printf("Loaded file successfully\n");
		
    fclose(file);
	
}


