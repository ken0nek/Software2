/* fact.c */
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int Debug = FALSE;

int fact (int x)
{
	if (x > 0) {
		if(Debug) {
			printf("x = %d\n", x);
		}
		return (x * fact(x - 1));
	} else {
		if(Debug) {
			printf("x = %d return 1\n", x);
		}
		return 1;
	}
}

int main(int argc, char const *argv[])
{
	int x, ret;
	while((argc > 1) && (argv[1][0] == '-')) {
		switch (argv[1][1]) {
			case 'd': Debug = TRUE; break;
		}
			argc--;
			argv++;
	}
	x = atoi(argv[1]);
	ret = fact(x);
	printf("ret = %d\n", ret);
	return 0;
}