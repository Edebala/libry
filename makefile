install: obj/book.o main.c book.h
	gcc main.c obj/book.o -o run -lm
obj/book.o: obj
	gcc book.c -c -o obj/book.o
obj:
	mkdir obj
clean:
	rm obj -r
	rm run
