all: mchava1P13

mchava1P13: hash.o mchava1P13.o
	gcc hash.o mchava1P13.o -o mchava1P13

hash.o: hash.c
	gcc -c hash.c

mchava1P13.o: mchava1P13.c
	gcc -c mchava1P13.c

clean:
	rm -rf *o mchava1P13