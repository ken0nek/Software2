#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

void output_rand(int length, char* filename) {
    FILE *fp;
    int i;
    if ((fp=fopen(filename, "w")) == NULL) {
        printf("Can't Open Input File.\n");
        exit(1);
    }
    srand(time(NULL));
    for (i=0; i<length; i++) {
        fprintf(fp, "%d\n", rand()%100);
    }
    fclose(fp);

    return;
}

int main(int argc, char** argv) {
    int c, length=100;
    char *filename="rand.txt";

    while ((c=getopt(argc, argv, "n:o:")) != -1) {
        switch (c) {
            case 'n':
                length = atoi(optarg);
                break;
            case 'o':
                filename = optarg;
        }
    }

    fprintf(stderr, "writing data with %d length to %s\n", 
            length, filename);
    output_rand(length, filename);

    return 0;
}
