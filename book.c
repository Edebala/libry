#include "book.h"

char* intToString(int a){
	int size = 1 +  (int) log10((double)a);
	char* c = (char*) calloc(size+1,sizeof(char));
	for(int i=size;i>=0;i--){
		c[i-1] = a%10 + '0';
		a/=10;
	}
	c[size] = 0;
	return c;
}

char* dateToString(Date *a){
	char *s = (char*) malloc(16);
	strcpy(s,intToString(a->year));
	strcat(s,"-");
	strcat(s,intToString(a->month));
	strcat(s,"-");
	strcat(s,intToString(a->day));
	return s;
}

void setDate(Date* date,int y,int m,int d){
	date->year = y;
	date->month = m;
	date->day = d;
}

Book *createBook
(char* title, char* author, char* language,char* genre,
Date *pDate, int timesBorrowed,int bPeriod, Date *lastB){
	Book *b = (Book*) malloc(sizeof(Book));

	b->title = (char*) malloc(strlen(title));
	b->author = (char*) malloc(strlen(author));
	b->language = (char*) malloc(strlen(language));
	b->genre = (char*) malloc(strlen(genre));

	strcpy(b->title,title);
	strcpy(b->author,author);
	strcpy(b->language,language);
	strcpy(b->genre,genre);

	setDate(&(b->publicationDate),pDate->year,
		pDate->month,pDate->day);

	b->timesBorrowed=timesBorrowed;
	b->borrowingPeriod=bPeriod;

	if(timesBorrowed != 0){
		b->lastBorrowed = (Date*) malloc(sizeof(Date));
		setDate(&(b->publicationDate),lastB->year,
			lastB->month,lastB->day);
	}
}

void showBook(Book* b){
	char* pDate = dateToString(&(b->publicationDate));
	char* lastB;
	if(b->timesBorrowed != 0)
		lastB = dateToString(b->lastBorrowed);
	printf("Title:             %s\nAuthor:            %s\nLanguage:          %s\nGenre:             %s\nPublicationDate:   %s\nBorrowing Period:  %i months\n",
		b->title,b->author,b->language,b->genre,pDate,b->borrowingPeriod
	);

	if(b->timesBorrowed != 0)
		printf("Times Borrowed:%i\nLast Time Borrowed:%s",b->timesBorrowed,lastB);
	else
		printf("Has not been Borrowed Yet!\n");

	free(pDate);
	if(b->timesBorrowed != 0)
		free(lastB);
}
/*
void loadBooksFromFile(Library* library ,char* source){
	FILE *f = fopen(source,"r");
	fscanf(f,&(library->numBooks));
	Book* buffer;
	for(int i=0;i<library->numBooks;i++){
		char titleBuffer[30], authorBuffer[30], languageBuffer[30], genreBuffer[30];
		int timesBorrowedBuffer,borrowingPeriodBuffer;
		Date pubDateBuffer;
		buffer = createBook();
	}

}

*/
