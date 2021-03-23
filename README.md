# libry
Library Managment tool, UNI Homework Project

Libry is a free and open source CLI solution for libraries
to manage their available books. With Libry you can keep a
database of every book, they can be searched for, sorted, 
and filtered in many ways. Libry can hold information about
the title,the author,the publisher,the genre, the publica-
tion date, the borrowing period of the book, whether it
can be borrowed, for how long can it be borrowed, when was
it borrowed last time, and how many times has it been
borrowed. Also by this data, Libry can conclude if the book
is currently available to borrow.

ValueSet:
1.Books
	a.ID
	b.Title
	c.Author
	d.Publisher
	e.Genre
	f.Publication Date
	g.Borrowing Period
	h.Last Time Borrowed
	i.Times Borrowed
	j.Condition

2.Borrows
	a.ID
	b.BookID
	c.PersonCNP
	d.PersonAge
	e.PersonFirstName
	f.PersonLastName
	g.Date
	h.ReturnDate
	i.MaxReturnDate
	j.Damage

Functions:
	1.CreateBook
	2.ReadBooksFromFile
	3.ListBooks
	4.SortBooks(Multiple Functions, probaby)
	5.BorrowBook
	6.ReturnBook
	7.RenovateBook(Restore Condition)
	8.RetireBook(The Book cannot be Borrowed anymore)
	9.RemoveBook
	10.Filter(Multiple Functions)

The dataset is picked from guttenberg.org.
