/* test-audio.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>

#define HZ 8000
#define CH 1
#define TM 3

int main(int argc, char *argv[]) {
    int fd;
    int i, ch, ret;
    unsigned char buf[TM*HZ*CH];

    /*fd = open("/dev/audio", O_RDWR);
    if (fd < 0) {
        printf("could not open /dev/audio\n");
        exit(1);
    }

    for (i=0; i < HZ; i++) {
        double w = (double)i / (double)HZ;
        for (ch=0; ch<CH; ch++) {
            buf[i*CH+ch] = (unsigned char)(sin(w * (440 * pow(1.05946, i/HZ)) * (ch+1)) * 200.0);
        }
    }

    ret = write(fd, buf, sizeof(buf));
    printf("buf = %d, %d\n", ret, sizeof(buf));
    close(fd);

    fd = open("audio.raw", O_WRONLY);
    write(fd, buf, sizeof(buf));
    close(fd);*/

    fd = open("audio.raw", O_RDONLY);
    read(fd, buf, sizeof(buf));
    close(fd);

    fd = open("/dev/audio", O_RDWR);
    if (fd < 0) {
        printf("could not open /dev/audio\n");
        exit(1);
    }
    ret = write(fd, buf, sizeof(buf));
    printf("buf = %d, %d\n", ret, sizeof(buf));
    close(fd);
}
