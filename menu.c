#include "project.h"

void menu(char **argv)
{
    didLoad = 0;
    char choice[4], d[4];


start1: printf("MAIN MENU\n---------\n");
        printf("Load(l), Save(s), Add(a), Delete(r), Display(d), Quit(q)\n");
        printf("Enter your choice: ");

    fgets(choice, sizeof(choice), stdin);
    if(strlen(choice) > 2) goto invldMsg1;
        switch(choice[0]){
            case 's':
                save(argv);
                break;
            case 'l':
                load(argv);
                break;
            case 'a':
                add();
                break;
            case 'r':
				if(didLoad == 0){ 
				printf("\nThere are no books loaded\n");
				printf("You have to load or add a book first\n");
				goto start1;
				}
				my_delete();
                getc(stdin);
                break;
            case 'd':
				if(didLoad == 0){ 
					printf("\nThere are no books loaded\n");
					printf("You have to load or add a book first\n");
					goto start1;
				}
start2:         printf("\nDISPLAY MENU\n------------\n");
                printf("Display by ID(i), Title(t), Author surname(s), Display all(a)\n");
                printf("Enter your choice: ");
                fgets(d, sizeof(d), stdin);
                if(strlen(d) > 2) goto invldMsg2;
                switch(d[0]){
                    case 's': 
                        displayAuthor();
                        break;
                    case 't':
                        displayTitle();
                        break;
                    case 'i':
                        displayID();
                        getc(stdin);
                        break;
                    case 'a':
                        display();
                        getc(stdin);
                    break;
                    default:
invldMsg2:              printf("\nerror: uknown command\n");
						rewind(stdin);
                        goto start2;
                    }
                    break;
            case 'q':
                return;
            default:
invldMsg1:      printf("\nerror: uknown command\n");
            }
            printf("\n");
            goto start1;
}


