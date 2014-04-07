# test1: main.c hello.c goodbye.c
# 	gcc -o test1 main.c hello.c goodbye.c

# test2: main.o hello.o goodbye.o
# 	gcc -o test2 main.o hello.o goodbye.o

# test3: main.o hello.o goodbye.o
# 	gcc -o $@ $^

test4: main.o hello.o goodbye.o
	gcc -o $@ $^

%.o: %.c
	gcc -o $@ -c $<

# main.o: main.c
# 	gcc -o $@ -c @^

# hello.o: hello.c
# 	gcc -o $@ -c @^

# goodbye.o: goodbye.c
# 	gcc -o $@ -c @^