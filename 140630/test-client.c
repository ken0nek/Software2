/* test-client.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]) {
    int fd;
    struct sockaddr_in server;

    fd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("157.82.13.119");
    server.sin_port = htons(80);

    if (connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connecting stream socket");
        exit(1);
    }

    char get_msg[] = "GET /index.html HTTP/1.0\n\n";
    write(fd, get_msg, sizeof(get_msg));

    char buf[256];
    int read_size = 256;
    while (read_size > 0) {
        read_size = read(fd, buf, sizeof(buf));
        write(1, buf, read_size);
    }

    close(fd);
}
