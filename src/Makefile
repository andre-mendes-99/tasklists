CFLAGS=-Wall
CC=gcc

test: test_tasks
	./test_tasks

test_tasks: tests/test_tasks.c models/tasks.o tests/unity.o
	$(CC) $(CFLAGS) -o test_tasks tests/test_tasks.c models/tasks.o tests/unity.o

models/tasks.o: models/tasks.c
	$(CC) $(CFLAGS) -c models/tasks.c -o models/tasks.o

tests/unity.o: tests/unity.c
	$(CC) $(CFLAGS) -c tests/unity.c -o tests/unity.o
