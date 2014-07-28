#include <stdio.h>
/* test-mmx.c*/

int main(int argc, char *argv[]) {
    short i=1, j=2, k;

# if 0
    asm ( assembler template
        : output operands
        : input operands
        : list of clobbered registers
        );
# endif
    asm volatile ("nop" :: "a" (i));
    asm volatile ("nop" :: "b" (j));
    asm volatile ("add %eax,%ebx");
    asm volatile ("nop" :"=b"(k));
    asm volatile ("emms");

    printf(" %3d + %3d = %3d\n", i, j, k);
    return 0;
}
