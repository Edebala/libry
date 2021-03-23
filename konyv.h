typedef struct{
	int year;
	int month;
	int day;
}Date;

typedef struct{
///The title of the book, ex. Winetou
	char* title;
///The author of the book ex. Karl May
	char* author;
///The publisher, that published the book. ex. Kriterion
	char* publisher;
///The "type" of the book, ex. Fantasy, SciFi etc.
	char* genre;
///The time of publication of the book
	Date publicationDate;
///How many times has the book been borrowed
	int timesBorrowed;
///For how long can the book be borrowed, in months
	int borrowingPeriod;
///The last time someone borrowed the book
	Date *lastBorrowed;
}Book;

Book *createBook
(char*,char*,char*,char*,Date*,int,int,Date*);

void showBook(Book*);
