CC = gcc
CFLAGS = -Wall -04

all: sort-gen sort1 sort2

%.o: %.c
	$(CC) $(CFLAGC) -o $@ -c $<

selection: selection.o sortlib.o
	$(CC) -o $@ $^

bubble: bubble.o sortlib.o
	$(CC) -o $@ $^

heap: heap.o sortlib.o
	$(CC) -o $@ $^

merge: merge.o sortlib.o
	$(CC) -o $@ $^

quick: quick.o sortlib.o
	$(CC) -o $@ $^

compare: compare.o sortlib.o selection.o bubble.o merge.o quick.o heap.o

sort-gen: sort-gen.o
	$(CC) -o $@ $^

test-student4: test-student4.cpp
	g++ -o $@ $<

clean:
	rm -f sort1 sort-gen sort1.o sort-gen.o sortlib.o test-student4
