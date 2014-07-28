#include<stdio.h>
#include<stdlib.h>

int* read_array(char *fname, int *num, int *len);
void print_array(int num[], int length);
void selection_sort(int *num, int length);
void selection_sort2(int *num, int start, int length);

/* int main(int argc, char *argv[]) { */
/*     int length, *num; */
/*     char *fname="rand.txt"; */
/*  */
/*     printf("reading from %s\n", fname); */
/*     num = read_array(fname, num, &length); */
/*  */
/*     print_array(num, length); */
/*     //selection_sort(num, length); */
/*     selection_sort2(num, 0, length); */
/*     print_array(num, length); */
/*  */
/*     free(num); */
/*     return 0; */
/* } */

void selection_sort(int *num, int length) {
    int i, n, tmp;
    int min, min_pos;
    for (i=0; i<length-1; i++) {
        //print_array(num, length);

        min = num[i]; // hypothetical min value
        min_pos = i; // hypothetical min value position
        for (n=i+1; n<length; n++) {
            if (num[n] < min) {
                // if comparing value is smaller than hypo min value
                // insert that value to min variant
                min = num[n];
                min_pos = n;
            }
        }

        // min and first num exchange
        tmp = num[i];
        num[i] = min;
        num[min_pos] = tmp;
    }
}

void selection_sort2(int *num, int start, int length) {
    int i, tmp;
    int min_pos = start, min = num[start];
    for (i=start; i<length; i++) {
        if (num[i] < min) {
            min = num[i];
            min_pos = i;
        }
    }
    tmp = num[start];
    num[start] = min;
    num[min_pos] = tmp;
    if (start < length-1) {
        selection_sort2(num, ++start, length);
    }
}
