FLAGS = -g -pedantic -std=c11 -Wall -Werror

static1: static_main dynamic1
	gcc $(FLAGS) static_main.o -L. libimpl1.so -o main

static2: static_main dynamic2
	gcc $(FLAGS) static_main.o -L. libimpl2.so -o main

static_main: static_main.c
	gcc $(FLAGS) -c static_main.c

dynamic1: declaration.h implementation1.c
	gcc $(FLAGS) -shared -o libimpl1.so -fPIC implementation1.c -lm

dynamic2: declaration.h implementation2.c
	gcc $(FLAGS) -shared -o libimpl2.so -fPIC implementation2.c -lm

clean:
	rm -rf *.o *.so main