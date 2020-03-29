CC=g++
CFLAGS=-Wall -Wextra -fno-exceptions -g -pedantic -O0 -I.
EXEC=testSLL

all:	$(EXEC)

testSLL: myFuncts.o main.o sllist.o
	$(CC) -o $@ myFuncts.o sllist.o main.o $(LDFLAGS)

myFuncts.o: myFuncts.cpp
	$(CC) -o $@ -c myFuncts.cpp $(CFLAGS)

sllist.o: sllist.cpp
	$(CC) -o $@ -c sllist.cpp $(CFLAGS)

main.o: main.cpp myFuncts.h sllist.h
	$(CC) -o $@ -c main.cpp $(CFLAGS)

clean:
	rm -f *.o core
	
mrproper: clean
	rm -f $(EXEC)
