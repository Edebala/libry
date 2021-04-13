#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int compareDate(void* a,void* b);
int compareString(void* a,void* b);
int compareInt(void* a,void* b);

void sortBooksByTitle(Library*);
void sortBooksByAuthor(Library*);
void sortBooksByGenre(Library*);
void sortBooksByPublicationDate(Library*);
void sortBooksByCondition(Library*);
void sortBooksByBorrowingTime(Library*);

char* copyString(char* string);

char* intToString(int a);

char* dateToString(Date *a);

#endif
