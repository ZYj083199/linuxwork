main.o:main.c
	gcc main.c -c
myhead.o:myhead.c
	gcc myhead.c -c
t:main.o myhead.o
	gcc main.o myhead.o -o main
clean:
	rm -f *.o
