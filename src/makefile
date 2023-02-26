CC = gcc
FLAGS = -g -pedantic -std=c11 -Wall -Werror

# Update $LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=$(pwd):$LD_LIBRARY_PATH

# lib1
functions1: functions.h functions1.c
	$(CC) $(FLAGS) -lm -shared -fPIC functions1.c -o libfuns1.so 

# lib2
functions2: functions.h functions2.c
	$(CC) $(FLAGS) -lm -shared -fPIC functions1.c -o libfuns2.so 

static_main: static_main.c
	$(CC) $(FLAGS) -lm -c static_main.c -o static_main.o

static1: functions1 static_main
	$(CC) -L. static_main.o -lfuns1 -o static1

static2: functions2 static_main
	$(CC) -L. static_main.o -lfuns2 -o static2

clean:
	rm *.o *.so static1 static2