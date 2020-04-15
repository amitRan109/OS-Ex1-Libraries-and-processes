CC=gcc
FLAGS=-Wall -g
all: main3 libHello

main3: main1_3.o 
	$(CC) $(FLAGS) -o main3 main1_3.o -ldl

libHello: libHello.so main1_1.o
	$(CC) $(FLAGS) -o libHello main1_1.o -L. ./libHello.so

libHello.so: hello_Ariel.o
	$(CC) -shared -o libHello.so hello_Ariel.o

hello_Ariel.o: hello_Ariel.c hello_Ariel.h 
	$(CC) $(FLAGS) -c -fPIC hello_Ariel.c hello_Ariel.h 

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c

main1_3.o: main1_3.c 
	$(CC) $(FLAGS) -c main1_3.c

.PHONY: clean all

clean:
	rm -f *.o *.so libHello main3