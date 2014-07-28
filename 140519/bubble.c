#include<stdio.h>
#include<stdlib.h>

int* read_array(char *fname, int *num, int *len);
void print_array(int num[], int length);
void bubble_sort(int *num, int length);

int main(int argc, char *argv[]) {
    int length, *num;
    char *fname="rand.txt";

    printf("reading from %s\n", fname);
    num = read_array(fname, num, &length);

    print_array(num, length);
    bubble_sort(num, length);
    print_array(num, length);

    free(num);
    return 0;
}

void bubble_sort(int *num, int length) {
    int i, n, tmp;
    for (i=0; i<length; i++) {
        for (n=length-1; n>i; n--) {
            if (num[n] < num[n-1]) {
                tmp = num[n];
                num[n] = num[n-1];
                num[n-1] = tmp;
            }
        }
    }
}

void bubble_sort2(int *num, int start, int length) {
    int n, tmp;
    for (n=length-1; n>start; n--) {
        if (num[n] < num[n-1]) {
            tmp = num[n]; num[n] = num[n-1]; num[n-1] = tmp;
        }
    }
    if (start < length-1) {
        bubble_sort2(num, ++start, length);
    }
}
