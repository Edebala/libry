#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "konyv.h"

Book *createBook
(char* title, char* author, char* publisher,
char* genre, Date *pDate, int timesBorrowed,
int bPeriod, Date *lastBorrowed)
{
	Book *b = (Book*) malloc(sizeof(Book));
	b->title = (char*) malloc(strlen(title));
	strcpy(b->title,title);
	
	b->author = (char*) malloc(strlen(author));
	strcpy(b->author,author);
	
	b->publisher = (char*) malloc(strlen(publisher));
	strcpy(b->publisher,publisher);

	b->genre = (char*) malloc(strlen(genre));
	strcpy(b->genre,genre);	

	b->publicationDate.year = pDate->year;
	b->publicationDate.month = pDate->month;
	b->publicationDate.day = pDate->day;

	b->timesBorrowed=timesBorrowed;
	b->borrowingPeriod=bPeriod;
	b->lastBorrowed = (Date*) malloc(sizeof(Date));
	if(lastBorrowed != 0)
	{	
		b->lastBorrowed->year = lastBorrowed->year;
		b->lastBorrowed->month = lastBorrowed->month;
		b->lastBorrowed->day = lastBorrowed->day;
	}
}

void showBook(Book* b){
	printf
	("Title:\t%s\nAuthor:\t%s\nPublisher:\t%s\nGenre:\t%s\n
		PublicationDate:\t%4.0i,%2.0i,%2.0i\nTimes Borrowed:\t%i\nBorrowing Period:\t%i\n",
		b->title,b->author,b->publisher,b->genre,
		b->publicationDate.year,b->publicationDate.month,b->publicationDate.day,
		b->timesBorrowed,b->borrowingPeriod
	);
	
	if(b->lastBorrowed != 0)
		printf
			("Last Time Borrowed:%4.0i,%2.0i,%2.0i",
				b->lastBorrowed->year,b->lastBorrowed->month,b->lastBorrowed->day
			);	
	else
		printf("Has not been Borrowed Yet!\n");
}
