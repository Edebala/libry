#include "book.h"

int main(){
	Library *lib =(Library*) malloc(sizeof(Library));
	loadBooksFromFile(lib,"output.txt");
	char choice = '9';
	int nr;
	do{
		switch(choice){
			case '1':
				sortBooks(lib,0);
				listBooks(lib);
				break;
			case '2':
				sortBooks(lib,1);
				listBooks(lib);
				break;
			case '3':
				sortBooks(lib,2);
				listBooks(lib);
				break;
			case '4':
				sortBooks(lib,3);
				listBooks(lib);
				break;
			case '5':
				sortBooks(lib,4);
				listBooks(lib);
				break;
			case '6':
				sortBooks(lib,5);
				listBooks(lib);
				break;
			case 'b':
				scanf("\n%d",&nr);
				borrowBook(lib,nr);
				break;
			case 'r':
				scanf("\n%i",&nr);
				returnBook(lib,nr);
				break;
			case '7':
				saveBooks(lib,"output.txt");
				return 1;
			case '9':
				printf("ListBy:\n 1:Title\t2:Author\t3:Language\t");
				printf("4:Genre \t5:Publication Date\t6:Condition\n");
				printf("9:Help\t0:Exit\n");
				printf("b:Borrow Book\tr:Return Book\n");
				printf("7:Save Books and Exit\n");
				break;
			default:
				printf("Your Input was invalid! Press 9 for Help!\n");
			}
			scanf("\n%c",&choice);
	}while(choice != '0');
	return 0;
}
