#include "book.h"

void setDate(Date* date,int y,int m,int d){
	date->year = y;
	date->month = m;
	date->day = d;
}

Book *createBook
	(char *title, char* author, char* language,char* genre,
	Date *pDate, int bPeriod,int timesBorrowed, Date *lastB,char* cond)
{
	Book *b = (Book*) malloc(sizeof(Book));
	b->title = copyString(title);
	b->author = copyString(author);
	b->language = copyString(language);
	b->genre = copyString(genre);
	b->condition = copyString(cond);

	b->timesBorrowed=timesBorrowed;
	b->borrowingPeriod=bPeriod;
	setDate(&(b->publicationDate),pDate->year,
		pDate->month,pDate->day);
	if(timesBorrowed){
		b->lastBorrowed = (Date*) malloc(sizeof(Date));
		setDate(b->lastBorrowed,lastB->year,
			lastB->month,lastB->day);
	}
	return b;
}

void showBook(Book* b){
	char *pDate = dateToString(&(b->publicationDate));
	printf("%36s\t%25s\t%12s\t%25s\t%12s\t%7i months\t%18s\t",
		b->title,b->author,b->language,
		b->genre,pDate,b->borrowingPeriod,b->condition);
	if(b->timesBorrowed != 0){
		char* lastB = dateToString(b->lastBorrowed);
		printf("%i\t%s\n",b->timesBorrowed,lastB);
		free(lastB);
	}
	else printf("Has not been Borrowed Yet!\n");
	free(pDate);
}

void loadBooksFromFile(Library* library ,char* source){
	FILE *f = fopen(source,"r");
	fscanf(f,"%d\n",&(library->numBooks));
	library -> Books = (Book**) malloc(library -> numBooks*sizeof(Book*));
	for(int i=0;i<library->numBooks;i++){
		char title[64],author[64],language[64],genre[64],condition[64];
		int timesBorrowed,borrowingPeriod,year,month,day;
		Date pubDate, lastBorrowed;
		fscanf(f,"%[^,],%[^,],%[^,],%[^,],%d-%d-%d,%d,%d,",
			title,author,language,genre,
			&(pubDate.year),&(pubDate.month),&(pubDate.day),
			&borrowingPeriod,&timesBorrowed);
		if(timesBorrowed){
			fscanf(f,"%d-%d-%d,",&(lastBorrowed.year),
			&(lastBorrowed.month),&(lastBorrowed.day));
		}
		fscanf(f,"%[^\n]\n",condition);
		library->Books[i] = createBook(title,author,language,
		genre,&pubDate,borrowingPeriod,
		timesBorrowed,&lastBorrowed,condition);
	}
	fclose(f);
}

void listBooks
	(Library* lib)
{
	char **s = (char**) malloc(10*sizeof(char*));
	s[0]="Title:";s[1]="Author:";s[2]="Language:";s[3]="Genre:";
	s[4] = "Pub. Date:"; s[5] = "Borrowing Period:";
	s[6] = "Times Borrowed(Months):"; s[7]="Condition:";
	printf("%36s\t%25s\t%12s\t%25s\t%12s\t%s\t%s\t%s\n",
		s[0],s[1],s[2],s[3],s[4],s[5],s[7],s[6]);
	for(int i=0;i<lib->numBooks;i++)
		showBook(lib->Books[i]);
	free(s);
}
