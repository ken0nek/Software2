#include <stdio.h>

// test-byteorder.c

void print_byte_ui(unsigned int s) {
    int i;
    unsigned char *p;
    p = (unsigned char*)&s;
    for (i=0; i<sizeof(unsigned int); i++) {
        printf("%02x", *p);
        p++;
    }
    printf("\n");
}
void print_byte_sh(short s) {
    int i;
    unsigned char *p;
    p = (unsigned char*)&s;
    for (i=0; i<sizeof(short); i++) {
        printf("%02x", *p);
        p++;
    }
    printf("\n");
}
void print_byte_i(int s) {
    int i;
    unsigned char *p;
    p = (unsigned char*)&s;
    for (i=0; i<sizeof(int); i++) {
        printf("%02x", *p);
        p++;
    }
    printf("\n");
}
void print_byte_l(long s) {
    int i;
    unsigned char *p;
    p = (unsigned char*)&s;
    for (i=0; i<sizeof(long); i++) {
        printf("%02x", *p);
        p++;
    }
    printf("\n");
}

int main() {
    unsigned int u1; // 32bit, 4byte
    short u2; // 16bit, 2byte
    int u3; // 32bit, 4byte
    long u4; // 64bit, 8byte
    u1 = 0x1234abcd;
    u2 = 0x1234;
    u3 = 0x1234abcd;
    u4 = 0x1234567890abcdef;
    printf("u1 = %x : ", u1);
    print_byte_ui(u1);
    printf("u2 = %x : ", u2);
    print_byte_sh(u2);
    printf("u3 = %x : ", u3);
    print_byte_i(u3);
    printf("u4 = %lx : ", u4);
    print_byte_l(u4);
    return 0;
}
