#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "book.h"

int compareDate(Date* a,Date* b);
int compareString(char* a,char* b);
int compareInt(const void* a,const void* b);

int cmpPubDate(const void*,const void*);
int cmpAuthor(const void*,const void*);
int cmpLanguage(const void*,const void*);
int cmpGenre(const void*,const void*);
int cmpCondition(const void*,const void*);
int cmpTitle(const void*,const void*);

void sortBooks(Library *lib,int c);

char* copyString(char* string);

char* intToString(int a);

char* dateToString(Date *a);

#endif
