test4: main.o hello.o goodbye.o
	gcc -o $@ $^

%.o: %.c
	gcc -o $@ -c $<