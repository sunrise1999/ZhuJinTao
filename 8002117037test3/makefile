newtest3:test.o fun.o
	gcc test.o fun.o -o newtest3
test.o:test.c head.h
	gcc test.c -c
fun.o:fun.c 
	gcc fun.c -c
clean:
	rm -f *.o
