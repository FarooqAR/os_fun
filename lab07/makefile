build: insdll compile_main
	gcc -Wall -o a.out main.o mylib.so

insdll: copydll
	sudo ldconfig

copydll: dll
	sudo cp mylib.so /usr/lib


dll: compile
	gcc -shared -o mylib.so add.o sub.o

compile:
	gcc -Wall -fPIC -c add.c sub.c

compile_main:
	gcc -Wall -c main.c

clean:
	sudo rm *.o *.out *.so /usr/lib/mylib.so

insdll_q: copydll_q
	sudo ldconfig

copydll_q: dll_q
	sudo cp mylib.so /usr/lib

dll_q: compile_q
	gcc -shared -o mylib.so my_q.o

compile_q:
	gcc -Wall -fPIC -c my_q.c

