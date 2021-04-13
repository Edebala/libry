#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "book.h"

int compareDate(void* a,void* b);
int compareString(void* a,void* b);
int compareInt(void* a,void* b);

void sortBooksByTitle();
void sortBooksByAuthor();
void sortBooksByGenre();
void sortBooksByPublicationDate();
void sortBooksByCondition();

char* copyString(char* string);

char* intToString(int a);

char* dateToString(Date *a);

#endif
