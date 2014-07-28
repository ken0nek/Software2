#include <stdio.h>
/* test-mmx.c*/

int main(int argc, char *argv[]) {
    short a[4] = {1, 2, 3, 4};
    short b[4] = {-4, -3, -2, -1};
    int c[2];
    int i=4, j=1, k=0;

# if 0
    asm ( assembler template
        : output operands
        : input operands
        : list of clobbered registers
        );
# endif
    asm volatile ("movq %0,%%mm0": :"m"(a[0]));
    asm volatile ("movq %0,%%mm1": :"m"(b[0]));
    /* PMADDWD--Packed Multiply and Add */
    /* SRC : | X3  | X2  | X1  | X0  |  */
    /* DEST: | Y3  | Y2  | Y1  | Y0  |  */
    /* DEST: |X3*Y3+X2*Y2+X1*Y1+X0*Y0|  */
    // asm volatile ("pmaddwd %%mm1,%%mm0"::); // mm0 の mm1 最大値
    asm volatile ("nop" :: "a" (a[0]));
    asm volatile ("nop" :: "b" (b[0]));
    asm volatile ("add %eax,%ebx");
    asm volatile ("nop" :"=b"(c[0]));
    // asm volatile ("movq %%mm0,%0":"=m"(c[0]));
    asm volatile ("emms");

    printf("%3d\n", k);
    for (i=0; i<4; i++) printf(" %3d", a[i]); printf("\n");
    for (i=0; i<4; i++) printf(" %3d", b[i]); printf("\n");
    for (i=0; i<2; i++) printf(" %3d", c[i]); printf("\n");
    return 0;
}
