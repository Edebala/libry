#include <stdio.h>
#include "book.h"

int main(){
	Library lib;
	loadBooksFromFile(&lib,"books.txt");
	return 1;
	listBooks(&lib);
	return 0;
}
