#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	int year;
	int month;
	int day;
}Date;

int compareDate(Date* a,Date* b);
int compareString(char* a,char* b);
int compareInt(int* a,int* b);

typedef struct{
///The title of the book, ex. Winetou
	char* title;
///The author of the book ex. Karl May
	char* author;
///The publisher, that published the book. ex. Kriterion
	char* language;
///The "type" of the book, ex. Fantasy, SciFi etc.
	char* genre;
///The time of publication of the book
	Date publicationDate;
///How many times has the book been borrowed
	int timesBorrowed;
///For how long can the book be borrowed, in months
	int borrowingPeriod;
///The last time someone borrowed the book
	Date *lastBorrowed;
///The Condition of the book
	char* condition;
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
void sortBooksByTitle();
void sortBooksByAuthor();
void sortBooksByGenre();
void sortBooksByPublicationDate();
void sortBooksByCondition();

void borrowBook(Book* books, int id);
