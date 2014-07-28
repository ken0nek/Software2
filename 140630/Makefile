CC = gcc

%: %.c
	${CC} -o $@ $<

test-thread: test-thread.c
	${CC} -o $@ $< -lpthread
