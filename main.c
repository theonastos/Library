#include <stdio.h>
#include "project.h"

struct Books listOfBook;

int main(int argc, char *argv[])
{
    if (argc != 2)
        argv[1] = ("default.txt");

        menu(argv);
	return 0;
}
