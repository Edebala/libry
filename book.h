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

#include "functions.h"

typedef struct{
	char* title;///The title of the book, ex. Winetou
	char* author;///The author of the book ex. Karl May
	char* language;///The publisher, that published the book. ex. Kriterion
	char* genre;///The "type" of the book, ex. Fantasy, SciFi etc.
	Date publicationDate;///The time of publication of the book
	int timesBorrowed;///How many times has the book been borrowed
	int borrowingPeriod;///For how long can the book be borrowed, in months
	Date *lastBorrowed;///The last time someone borrowed the book
	char* condition;///The Condition of the book
}Book;

typedef struct{
	int numBooks;
	Book** Books;
}Library;

Book *createBook
(char*,char*,char*,char*,Date*,int,int,Date*,char*);

void showBook(Book*);
void setDate(Date* date,int y,int m,int d);
void loadBooksFromFile(Library* library,char* filename);
void listBooks(Library *library);

void borrowBook(Book* books, int id,Date* date);

#endif
