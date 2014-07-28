/* heap.c */
#include<stdio.h>
#include<stdlib.h>
void heap_add(int *num, int length, int c) {
    int p, tmp;
    while (1) {
        p = (c-1) / 2;
        printf("%d ", p);
        if (c<0) break;
        if (num[p] <= num[c]) break;
        tmp = num[p]; num[p] = num[c]; num[c] = tmp;
        c = p;
    }
}

void heap_del(int *num, int length, int p) {
    int c, tmp;
    while (1) {
        c = p*2 + 1; // 子のインデックスを計算
        if (c >= length)
            break;
        if (c+1 < length && num[c+1] <= num[c])
            c = c+1;
        // 親のほうが小さい場合はbreak
        if (num[p] <= num[c])
            break;
        tmp=num[p];num[p]=num[c];num[c]=tmp;
        p = c; // 子ノードを新たな親ノードにする
    }
}

void heap_sort(int *num, int length) {
    int tmp, i;
    // 最初のヒープを作る
    for (i=1; i<length; i++) {
        heap_add(num, length, i);
    }
    print_array(num, length);
    // ヒープから最小値を抜き配列の後ろから詰めていく
    for (i=0; i<length; i++) {
        tmp=num[length-1-i]; num[length-1-i]=num[0]; num[0]=tmp;
        heap_del(num, length-1-i, 0);
    }
    // 逆順にする
    for (i=0; i<length/2; i++) {
        tmp = num[i]; num[i] = num[length-i-1]; num[length-i-1] = tmp;
    }
}

int main(int argc, char *argv[]) {
    int length, *num;
    char *fname="rand.txt";

    printf("reading from %s\n", fname);
    num = read_array(fname, num, &length);

    print_array(num, length);
    heap_sort(num, length);
    print_array(num, length);

    //free(num);
    return 0;
}
