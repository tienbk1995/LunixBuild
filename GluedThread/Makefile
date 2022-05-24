LIBNAME=libglthread.a
TARGET:${LIBNAME} exe
${LIBNAME}:glthreads.o
	ar rs ${LIBNAME} glthreads.o
exe:main.o ${LIBNAME}
	gcc -g main.o -o run.exe -L . -lglthread
glthreads.o:glthreads.c
	gcc -g -c -I . glthreads.c -o glthreads.o
main.o:main.c
	gcc -g -c -I . main.c -o main.o
clean:
	rm *.o
	rm *.exe
	rm ${LIBNAME}