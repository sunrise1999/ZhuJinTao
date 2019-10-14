test:test.o fun.o fun2.o
	gcc -o test test.c ./libfunc.so -I./ -ldl
test.o:test.c head.h stdio.h dlfcn.h stdlib.h>
	gcc test.c -c
libfunc.so :fun.c fun2.c
	gcc -fpic -shared -o libtest.so fun.c fun2.c
clean:
	rm -f *.o
