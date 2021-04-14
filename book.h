#ifndef BOOK_H 
#define BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	int year;
	int month;
	int day;
}Date;

typedef struct{
	char* title;///ex. Winetou
	char* author;///ex. Karl May
	char* language;///ex. English
	char* genre;///ex. Fantasy, SciFi etc.
	Date publicationDate;///The time of publication of the book
	int timesBorrowed;///How many times has the book been borrowed
	int borrowingPeriod;///For how many months can it be borrowed
	Date *lastBorrowed;///The last time someone borrowed the book
	char* condition;
}Book;

typedef struct{
	int numBooks;
	Book** Books;
}Library;

#include "functions.h"

Book *createBook
(char*,char*,char*,char*,Date*,int,int,Date*,char*);

void showBook(Book*);
void setDate(Date* date,int y,int m,int d);
void loadBooksFromFile(Library* library,char* filename);
void listBooks(Library *library);

#endif
