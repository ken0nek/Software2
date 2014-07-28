#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int print_bit (float f) {
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

int main(int argc, char* argv[])
{
    float a, b, c, sd, alpha, beta, z;
    double a2, b2, c2, sd2, alpha2, beta2, z2;

    a = a2 =  1.00000;
    b = b2 = -333.333;
    c = c2 = 1.23456;

    printf("a = %-12f : ", a);
    print_bit(a);
    printf("b = %-12f : ", b);
    print_bit(b);
    printf("c = %-12f : ", c);
    print_bit(c);

    sd = sqrt( b*b - 4*a*c );
    sd2 = sqrt( b2*b2 - 4*a2*c2);

    alpha = (-b + sd) / (2*a);
    beta = (-b - sd) / (2*a);

    alpha2 = (-b2 + sd2) / (2*a2);
    beta2 = (-b2 - sd2) / (2*a2);

    printf("alpha = %15e    beta = %15e\n", alpha, beta);
    printf("alpha2= %15e    beta2= %15e\n", alpha2, beta2);
    printf("( sd= %f )\n", sd);
    printf("( sd= %lf )\n", sd2);
    return 0;
}
