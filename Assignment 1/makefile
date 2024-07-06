CC = gcc
CFLAGS = -g -ansi -pedantic -Wall -o
OBJS = main.o students.o courses.o registration.o

all: registration_system

registration_system: $(OBJS)
	$(CC) $(CFLAGS) -o registration_system $(OBJS)

main.o: main.c students.h courses.h registration.h
	$(CC) $(CFLAGS) -c99 main.c

students.o: students.c students.h
	$(CC) $(CFLAGS) -c99 students.c

courses.o: courses.c courses.h
	$(CC) $(CFLAGS) -c99 courses.c

registration.o: registration.c registration.h students.h courses.h
	$(CC) $(CFLAGS) -c99 registration.c

clean:
	rm -f registration_system $(OBJS)
