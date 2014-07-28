#include<stdio.h>
#include<stdlib.h>
int* read_array(char *fname, int *num, int *len);
void print_array(int num[], int length);
void merge(int *num, int left, int right, int size);
void merge_sort(int *num, int left, int right);

int main(int argc, char *argv[]) {
    int length, *num;
    char *fname="rand.txt";

    printf("reading from %s\n", fname);
    num = read_array(fname, num, &length);

    print_array(num, length);
    merge_sort(num, 0, length-1);
    print_array(num, length);

    free(num);
    return 0;
}

/* *num:  ソートする配列のポインタ
 * left:  2つに分けた配列の左側先頭のインデックス
 * right: 右側先頭のインデックス
 * size:  配列numの長さ
*/
void merge(int *num, int left, int right, int size) {
    int *tmp, h, i, j, k, l;
    tmp = (int*)malloc((left+size)*sizeof(int));
    i = left;  // 列iのインデックスのカーソル
    j = right; // 列jのインデックスのカーソル
    k = left;  // 新しいソート済みの列のインデックスのカーソル
    l = left + size; // 列jの末尾のインデックス
    // 列iが終了,または列jが終了するまで繰り返す
    while ((i<right) && (j<l)) { 
        // 列iと列jのカーソル位置の数を比べて、小さい方を取り出す
        if (num[i] < num[j]) {
            tmp[k] = num[i];
            i++; // 列iにおいてカーソルを一つ進める
        } else {
            tmp[k] = num[j];
            j++; // 列jにおいてカーソルを一つ進める
        }
        k++; // 列kにおいてカーソルを一つ進める
    }
    // 列jがiよりも先に終わった場合にその要素を列kに追加する処理
    if (i<right) {
        for (h=i; h<right; h++) {
            tmp[k] = num[h];
            k++;
        }
    }
    // 列iがjよりも先に終わった場合にその要素を列kに追加する処理
    if (j<l) {
        for (h=j; h<l; h++) {
            tmp[k] = num[h];
            k++;
        }
    }
    // ソート済み配列tmpをnumに入れ直す
    for (h=left; h<l; h++) {
        num[h] = tmp[h];
    }
    free(tmp);
}

void merge_sort(int *num, int left, int right) {
    int middle;
    if (left < right) {
        middle = (right + left) / 2;
        merge_sort(num, left, middle);
        merge_sort(num, middle+1, right);
        merge(num, left, middle+1, right-left+1);
    }
}
