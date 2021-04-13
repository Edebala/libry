#include "functions.h"
#include "book.h"

int compareDate(Date* a,Date* b){
	return (a->year==b->year?(a->month==b->month?(a->day==b->day?0:
			a->day-b->day):a->month-b->month):a->year-b->year);
}

int compareInt(const void* a,const void* b){
	return(*((int*)a)-*((int*)b));
}

int compareByPublicationDate(const void*a,const void*b){
	return compareDate(
		&((*(Book**)a)->publicationDate),&((*(Book**)b)->publicationDate));
}

int compareByTitle(const void*a,const void*b){
	return strcmp((*(Book**)a)->title,(*(Book**)b)->title);
}
int compareByAuthor(const void*a,const void*b){
	return strcmp((*(Book**)a)->author,(*(Book**)b)->author);
}
int compareByLanguage(const void*a,const void*b){
	return strcmp((*(Book**)a)->language,(*(Book**)b)->language);
}
int compareByGenre(const void*a,const void*b){
	return strcmp((*(Book**)a)->genre,(*(Book**)b)->genre);
}
int compareByCondition(const void*a,const void*b){
	return strcmp((*(Book**)a)->condition,(*(Book**)b)->condition);
}
void sortBooks(Library *lib,int c){

	switch(c){
		case 0:qsort(lib->Books,lib->numBooks,sizeof(Book*),compareByTitle);return;
		case 1:qsort(lib->Books,lib->numBooks,sizeof(Book*),compareByAuthor);return;
		case 2:qsort(lib->Books,lib->numBooks,sizeof(Book*),compareByLanguage);return;
		case 3:qsort(lib->Books,lib->numBooks,sizeof(Book*),compareByGenre);return;
		case 4:qsort(lib->Books,lib->numBooks,sizeof(Book*),compareByPublicationDate);return;
		case 5:qsort(lib->Books,lib->numBooks,sizeof(Book*),compareByCondition);return;
	}
}

char* copyString(char* string){
	char* newString = (char*) malloc(strlen(string));
	strcpy(newString,string);
	return newString;
}

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
