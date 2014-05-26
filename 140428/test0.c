/* test0.c */
#include <stdio.h>

/*
 *引数: 整数i, j
 *返値: iとjの和となる整数
 *機能: 引数の和を計算し返す関数
 */
int test(int i, int j)
{
	return (i + j);
}

int main(int argc, char const *argv[])
{
	int i, j /* 入力となる整数i, j */
	int k; /* iとjの和 */
	i = 3;
	j = 2;

	/* iとjを足して、kに代入する */
	k = test(i, j);

	/* kが5よりも大きいか、それ以外かを判定し、それに応じて結果を表示する */
	if(k > 5) {
		printf(">5\n");
	} else {
		printf("<=5\n");
	}
	return 0;
}