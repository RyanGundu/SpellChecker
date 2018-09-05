CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -c -Iinclude

all: bin/main bin/testMain

bin/HashTableAPI.o: src/HashTableAPI.c
	$(CC) $(CFLAGS) src/HashTableAPI.c -o bin/HashTableAPI.o

bin/userDefined.o: src/userDefined.c
	$(CC) $(CFLAGS) src/userDefined.c -o bin/userDefined.o

bin/commandLine.o: src/commandLine.c
	$(CC) $(CFLAGS) src/commandLine.c -o bin/commandLine.o

bin/main.o: src/main.c
	$(CC) $(CFLAGS) src/main.c -o bin/main.o

bin/main: bin/main.o bin/HashTableAPI.o bin/userDefined.o bin/commandLine.o 
	$(CC) bin/main.o bin/HashTableAPI.o bin/userDefined.o bin/commandLine.o -o bin/runMe 

bin/testMain.o: src/testMain.c
	$(CC) $(CFLAGS) src/testMain.c -o bin/testMain.o 

bin/testMain: bin/testMain.o bin/userDefined.o bin/HashTableAPI.o bin/commandLine.o 
	$(CC) bin/testMain.o bin/userDefined.o bin/HashTableAPI.o bin/commandLine.o -o bin/runTest

run:
	./bin/runMe dictionary.txt

runTest:
	./bin/runTest

clean:
	rm bin/*.o
	rm bin/runMe
	rm bin/runTest
	
