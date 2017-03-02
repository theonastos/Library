#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 256
#define SUMMARY_SIZE 2048
#define NAME_SIZE 56

struct Author{
    char firstName[NAME_SIZE];
    char lastName[NAME_SIZE];
};

struct Book{
    int id;
    char title[TITLE_SIZE];
    char summary[SUMMARY_SIZE];
    int numberOfAuthors;
    struct Author *authors;
};

struct Books{
    struct Book *arr;
    int numOfBooks;
};

extern struct Books listOfBook;
int numberOfBooks, didLoad;

void save(char **argv);     //save to file everything the arr has
void load(char **argv);     //loads books from file
void menu(char **argv);     //main menu
void add(void);      //adds a book
void my_delete(void);    //deletes a book

//Displays
void display(void);          //display all
void displayID(void);        // display by id
void displayTitle(void);     //display by Title
void displayAuthor(void);

int seqSearch(int key, struct Books *struct1);      //sequential search for integers
int seqTSearch(char *key, struct Books *struct1);     //sequential search for title
int *seqASearch(char *key, struct Books *struct1);  //sequential search for authors
void swapStructs(struct Book *struct1, struct Book *struct2); //
int numDigits(int number);  //counts the didits of an integer
void trailingNL(char *str);     //removes the trailing lines from a string
void print(int i); //includes print commands for all the variables of a struct

#endif // PROJECT_H_INCLUDED
