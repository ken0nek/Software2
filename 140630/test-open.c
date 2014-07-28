/* test-open.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[256];
    int read_size=256;
    int total_write_byte=0;

    if (argc != 2) {
        printf("%s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        printf("could not open %s\n", argv[1]);
        exit(1);
    }

    while (read_size > 0) {
        read_size = read(fd, buf, sizeof(buf));
        total_write_byte += write(1, buf, read_size);
    }
    printf(";; total write bytes to stdout%d\n", total_write_byte);

    close(fd);
}
