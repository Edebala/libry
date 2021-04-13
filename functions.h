#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "book.h"

int compareDate(Date* a,Date* b);
int compareString(char* a,char* b);
int compareInt(const void* a,const void* b);

int compareByPublicationDate(const void*,const void*);
int compareByAuthor(const void*,const void*);
int compareByLanguage(const void*,const void*);
int compareByGenre(const void*,const void*);
int compareByCondition(const void*,const void*);
int compareByTitle(const void*,const void*);

void sortBooks(Library *lib,int c);

char* copyString(char* string);

char* intToString(int a);

char* dateToString(Date *a);

#endif
