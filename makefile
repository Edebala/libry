install: obj/book.o main.c book.h functions.h obj/functions.o
	gcc main.c obj/book.o obj/functions.o -o run -lm
obj/functions.o: obj
	gcc functions.c -c -o obj/functions.o
obj/book.o: obj
	gcc book.c -c -o obj/book.o
obj:
	mkdir obj
clean:
	rm obj -r
	rm run
