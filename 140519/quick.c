#include<stdio.h>
#include<stdlib.h>
int* read_array(char *fname, int *num, int *len);
void print_array(int num[], int length);
void quick_sort(int *num, int first, int last);

int main(int argc, char *argv[]) {
    int length, *num;
    char *fname="rand.txt";

    printf("reading from %s\n", fname);
    num = read_array(fname, num, &length);

    print_array(num, length);
    quick_sort(num, 0, length-1);
    print_array(num, length);

    free(num);
    return 0;
}

void quick_sort(int *num, int first, int last) {
    int i, j, x, t;

    x = (num[first] + num[last]) / 2;
    i = first;
    j = last;
    while (1) {
        while (num[i] < x) i++;
        while (x < num[j]) j--;
        if (i >= j) break;
        t=num[i]; num[i]=num[j]; num[j]=t;
        i++; j--;
    }
    if (first < i-1) {
        quick_sort(num, first, i-1);
    }
    if (j+1 < last) {
        quick_sort(num, j+1, last);
    }
}
