#include <stdio.h>
#include "book.h"

int main(){
	Library *lib =(Library*) malloc(sizeof(Library));
	loadBooksFromFile(lib,"books.txt");
	listBooks(lib);
	printf("----Title-------------------------------------\n");
	sortBooks(lib,0);
	listBooks(lib);
	printf("----Author------------------------------------\n");
	sortBooks(lib,1);
	listBooks(lib);
	printf("--Language------------------------------------\n");
	sortBooks(lib,2);
	listBooks(lib);
	printf("-----Genre------------------------------------\n");
	sortBooks(lib,3);
	listBooks(lib);
	printf("--Publication Date----------------------------\n");
	sortBooks(lib,4);
	listBooks(lib);
	printf("----------Condition---------------------------\n");
	sortBooks(lib,5);
	listBooks(lib);
	return 0;
}
