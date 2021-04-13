#include "functions.h"

int compareString(void *a, void *b){
	char *sa = (char*) a;
	char *sb = (char*) b;
	return strcmp(a,b);
}

int compareDate(void* da,void* db)
{
	Date* a = (Date*) da;
	Date* b = (Date*) db;
	return (a->year==b->year?(a->month==b->month?(a->day==b->day?0:
			a->day-b->day):a->month-b->month):a->year-b->year);

	/*if( a -> year > b a-> year)
		return 1;
	if ( a -> year < b -> year)
		return -1;
	if (a -> year == b -> year)
	{
		if( a -> month > b -> month)
			return 1;
		if (a ->month < b-> month)
			return -1;
		if (a -> month == b -> month)
		{
		if (a -> day > b -> day)
			return 1;
		if( a -> day < b -> day)
			return -1;
		if (a -> day == b -> day)
			return 0;
		}
	}*/
}

int compareInt(void* a,void* b){
	//return(*((int*)a)-*((int*)b));
    int *ia =(int *) a;
    int *ib =(int *) b;
if(*ia > *ib) return 1;
if(*ia < *ib) return -1;
if(*ia == *ib )return 0;
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
