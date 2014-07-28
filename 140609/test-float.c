#include <stdio.h>
void print_bit (float f) {
    int i;
    unsigned int *j = ((unsigned int *)&f);
    unsigned int s = *j;
    for (i=0; i<32; i++) {
        printf("%c", ((0x80000000)&s)?'1':'0');
        if ( (i==0) || (i==8) ) printf(" ");
        s = s << 1;
    }
    printf("\n");
}
int main() {
    float f = 2.625; // 32bit, 4 byte
    float ten = 10.0;
    printf("f = %-12f : ", f);
    print_bit(f);
    printf("ten = %-12f : ", ten);
    print_bit(ten);
    printf("10 - f = %-12f\n", ten - f);

    return 0;
}
