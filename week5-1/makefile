newtest1:test.o fun.o fun2.o
	gcc test.o fun.o fun2.o -o newtest1
test.o:test.c head.h
	gcc test.c -c
fun.o:fun.c 
	gcc fun.c -c
fun2.o:fun2.c 
	gcc fun2.c -c
clean:
	rm -f *.o
