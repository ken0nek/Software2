/* test-open.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd1, fd2;
    char buf[256];
    int read_size=256;
    int total_write_byte=0;

    if (argc != 3) {
        printf("%s <filename1> <filename2>\n", argv[0]);
        exit(1);
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 < 0) {
        printf("could not open %s\n", argv[1]);
        exit(1);
    }

    fd2 = creat(argv[2], S_IWRITE);
    if (fd2 < 0) {
        printf("could not open %s\n", argv[2]);
        exit(1);
    }

    while (read_size > 0) {
        read_size = read(fd1, buf, sizeof(buf));
        total_write_byte += write(fd2, buf, read_size);
        /* total_write_byte += write(1, buf, read_size); */
    }
    printf(";; total write bytes to stdout%d\n", total_write_byte);

    close(fd1);
    close(fd2);
}
