#include "book.h"

void setDate(Date* date,int y,int m,int d){
	date->year = y;
	date->month = m;
	date->day = d;
}

Book *createBook
	(char *title, char* author, char* language,char* genre,
	Date *pDate, int bPeriod,int timesBorrowed, Date *lastB,
	char* cond,int avail)
{
	Book *b = (Book*) malloc(sizeof(Book));
	b->title = copyString(title);
	b->author = copyString(author);
	b->language = copyString(language);
	b->genre = copyString(genre);
	b->condition = copyString(cond);
	b->available = avail;
	b->timesBorrowed=timesBorrowed;
	b->borrowingPeriod=bPeriod;
	setDate(&(b->publicationDate),pDate->year, pDate->month,pDate->day);
	if(timesBorrowed){
		b->lastBorrowed = (Date*) malloc(sizeof(Date));
		setDate(b->lastBorrowed,lastB->year,
			lastB->month,lastB->day);
	}
	return b;
}

void showBook(Book* b){
	char *pDate = dateToString(&(b->publicationDate));
	printf("%36s\t%25s\t%12s\t%25s\t%12s\t%7i months\t%18s\t%s\t",
		b->title,b->author,b->language,
		b->genre,pDate,b->borrowingPeriod,b->condition,
		b->available?"AVAILABLE": "UNAVAILA.");
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
	fscanf(f,"%d",&(library->nr));
	library -> Books = (Book**)
		malloc(library -> nr*sizeof(Book*));
	for(int i=0;i<library->nr;i++){
		char title[64],author[64],language[64],genre[64],condition[64];
		int timesBorrowed,borrowingPeriod,year,month,day,available;
		Date pubDate, lastBorrowed;
		fscanf(f,"\n%[^,],%[^,],%[^,],%[^,],%d-%d-%d,%d,%d,%[^,],%d,",
			title,author,language,genre,
			&(pubDate.year),&(pubDate.month),&(pubDate.day),
			&borrowingPeriod,&timesBorrowed,condition,&available);
		if(timesBorrowed){
			fscanf(f,"%d-%d-%d,",&(lastBorrowed.year),
			&(lastBorrowed.month),&(lastBorrowed.day));
		}
		library->Books[i] = createBook(title,author,language,
		genre,&pubDate,borrowingPeriod,
		timesBorrowed,&lastBorrowed,condition,available);
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
	printf("%39s\t%25s\t%12s\t%25s\t%12s\t%s\t%s\t\t\t%s\n",
		s[0],s[1],s[2],s[3],s[4],s[5],s[7],s[6]);
	for(int i=0;i<lib->nr;i++){
		printf("%3d",i);
		showBook(lib->Books[i]);
		if(i%8 == 7)printf("\n");
	}
	free(s);
}

void borrowBook(Library* lib, int p){
	if(p >= lib->nr){
		printf("ERROR:BOOK DOES NOT EXIST\n");
		return;
	}else
	if(lib->Books[p]->available == 0 || lib->Books[p]->borrowingPeriod == 0){
		printf("SORRY, THAT BOOK IS NOT AVAILABLE RIGHT NOW\n");
		return;
	}else{
	lib->Books[p]->available = 0;
	if(lib->Books[p]->lastBorrowed == 0)
		lib->Books[p]->lastBorrowed =(Date*) malloc(sizeof(Date));
	setDate(lib->Books[p]->lastBorrowed,2021,5,5);
	lib->Books[p]->timesBorrowed++;
	printf("BOOK BORROWED SUCCESSFULLY\n");
}};

void returnBook(Library* lib, int p){
	if(p >= lib->nr){
		printf("ERROR:BOOK DOES NOT EXIST\n");
		return;
	}else
	if(lib->Books[p]->available == 0 && lib->Books[p]->borrowingPeriod == 0){
		printf("IT SEEMS LIKE THIS BOOK SHOULDN'T HAVE EVEN GOT OUT...\n");
		return;
	}else
	lib->Books[p]->available = 1;
};

void saveBooks(Library* lib, char* file){
	FILE *f = fopen(file,"w");
	fprintf(f,"%d\n",lib->nr);
	for(int i=0;i<lib->nr;i++){
		fprintf(f,"%s,%s,%s,%s,%s,%d,%d,%s,%d",
			lib->Books[i]->title,lib->Books[i]->author,lib->Books[i]->language,
			lib->Books[i]->genre,dateToString(&lib->Books[i]->publicationDate),
			lib->Books[i]->borrowingPeriod,lib->Books[i]->timesBorrowed,
			lib->Books[i]->condition,lib->Books[i]->available);

		if(lib->Books[i]->timesBorrowed)
			fprintf(f,",%s",dateToString(lib->Books[i]->lastBorrowed));
	fprintf(f,"\n");
	}
	fclose(f);
}
