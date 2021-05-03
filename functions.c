#include "functions.h"
#include "book.h"

int compareDate(Date* a,Date* b){
	return (a->year==b->year?(a->month==b->month?(a->day==b->day?0:
			a->day-b->day):a->month-b->month):a->year-b->year);
}

int compareInt(const void* a,const void* b){
	return(*((int*)a)-*((int*)b));
}
int cmpPubDate(const void*a,const void*b){
	return compareDate(
		&((*(Book**)a)->publicationDate),&((*(Book**)b)->publicationDate));
}
int cmpTitle(const void*a,const void*b){
	return strcmp((*(Book**)a)->title,(*(Book**)b)->title);
}
int cmpAuthor(const void*a,const void*b){
	return strcmp((*(Book**)a)->author,(*(Book**)b)->author);
}
int cmpLanguage(const void*a,const void*b){
	return strcmp((*(Book**)a)->language,(*(Book**)b)->language);
}
int cmpGenre(const void*a,const void*b){
	return strcmp((*(Book**)a)->genre,(*(Book**)b)->genre);
}
int cmpCondition(const void*a,const void*b){
	return strcmp((*(Book**)a)->condition,(*(Book**)b)->condition);
}

void sortBooks(Library *lib,int c){
	int (*a[6])(const void*,const void*) = {
		cmpTitle, cmpAuthor, cmpLanguage,
		cmpGenre, cmpPubDate, cmpCondition};
	qsort(lib->Books,lib->nr,sizeof(Book*),a[c]);
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
