FLAGS = -g -pedantic -std=c11 -Wall -Werror

static_main: static_main.c
	gcc $(FLAGS) -c static_main.c


dynamic1: declaration.h implementation1.c
	gcc $(FLAGS) -shared -o libimpl1.so -fPIC implementation1.c

dynamic2: declaration.h implementation2.c
	gcc $(FLAGS) -shared -o libimpl2.so -fPIC implementation2.c

clean:
	rm -rf *.o *.so solution