main.o:main.c
	gcc main.c -c
fun.o:fun.c
	gcc fun.c -c
fun1.o:fun1.c
	gcc fun1.c -c
fun2.o:fun2.c
	gcc fun2.c -c
t:main.o fun.o fun1.o fun2.o
	gcc main.o fun.o fun1.o fun2.o -o t
clean:
	rm -f *.o
