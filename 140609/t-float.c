/* t-float.c */
#include <stdio.h>
#include <stdlib.h>

void print_bit(float f);

int main(int argc, char* argv[]) {
    float f = 2.625;
    printf("f = %-12f : ", f);
    print_bit(f);

    return 0;
}
void print_bit(float f) {
    int i;
    unsigned int *j = ((unsigned int *)&f);
    unsigned int s = *j;
    for (i=0; i<32; i++) {
        printf("%c", ((0x80000000)&s) ? '1' : '0');
        if (i==0 || i==8) printf(" ");
        s = s << 1;
    }
    printf("\n");
}
