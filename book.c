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

char* dateToString
	(Date *a)
{
	char *s = (char*) malloc(16);
	strcpy(s,intToString(a->year));
	strcat(s,"-");
	strcat(s,intToString(a->month));
	strcat(s,"-");
	strcat(s,intToString(a->day));
	return s;
}

void setDate
	(Date* date,int y,int m,int d)
{
	date->year = y;
	date->month = m;
	date->day = d;
}

Book *createBook
	(char* title, char* author, char* language,char* genre,
	Date *pDate, int bPeriod,int timesBorrowed, Date *lastB,char* cond)
{
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

	if(timesBorrowed){
		b->lastBorrowed = (Date*) malloc(sizeof(Date));
		setDate(b->lastBorrowed,lastB->year,
			lastB->month,lastB->day);
	}

	b->condition = cond;
}

void showBook
	(Book* b)
{
	char* pDate = dateToString(&(b->publicationDate));
	char* lastB;
	char** s = (char**) malloc(7*sizeof(char*));
	s[0] = "Title:", s[1] = "Author:", s[2] = "Language:", s[3] = "Genre:";
	s[4] = "Publication Date:", s[5] = "Borrowing Period:", s[6]=" months";
	if(b->timesBorrowed)
		lastB = dateToString(b->lastBorrowed);
	printf("%17s%s\n%17s%s\n%17s%s\n%17s%s\n%17s%s\n%17s%i%s\n",
		s[0],b->title,s[1],b->author,s[2],b->language,s[3],b->genre,s[4],pDate,
		s[5],b->borrowingPeriod,s[6]);
	if(b->timesBorrowed)
		printf("  Times Borrowed:%i\n   Last Borrowed:%s\n",
		b->timesBorrowed,lastB);
	else
		printf("Has not been Borrowed Yet!\n");
	printf("       Condition:%s\n\n",b->condition);
	free(pDate);
	if(b->timesBorrowed != 0)
		free(lastB);
		free(s);
}

void loadBooksFromFile
	(Library* library ,char* source)
{
	FILE *f = fopen(source,"r");
	fscanf(f,"%d\n",&(library->numBooks));
	library -> Books = (Book**) malloc(library -> numBooks*sizeof(Book*));
	for(int i=0;i<library->numBooks;i++){	
		char title[30], author[30],
			language[30], genre[30],
			condition[30];
		int timesBorrowed,borrowingPeriod,year,month,day;
		Date pubDate, lastBorrowed;
		fscanf(f,"%[^,],%[^,],%[^,],%[^,],%d-%d-%d,%d,%d,",
			title,author,language,genre,
			&(pubDate.year),&(pubDate.month),&(pubDate.day),
			&borrowingPeriod,&timesBorrowed);
		if(timesBorrowed){
			fscanf(f,"%d-%d-%d,",
				&(lastBorrowed.year),&(lastBorrowed.month),&(lastBorrowed.day));
		}
		fscanf(f,"%[^\n]\n",condition);
		library->Books[i] = createBook(title,author,language,genre,
			&pubDate,borrowingPeriod,timesBorrowed,&lastBorrowed,condition);
		  showBook(library->Books[i]);
	}
	fclose(f);
}

void listBooks
	(Library* lib)
{
	for(int i=0;i<lib->numBooks;i++)
		showBook(lib->Books[i]);
}
