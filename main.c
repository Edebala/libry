#include <stdio.h>
#include "book.h"

int main(){
	Library lib;
	loadBooksFromFile(&lib,"books.txt");
	listBooks(&lib);
	int a=6,b=4;
	printf("%d\n",compareInt(&a,&b));
	printf("%d\n",compareInt(&b,&a));
	printf("%d\n",compareInt(&a,&a));

	return 0;
}
