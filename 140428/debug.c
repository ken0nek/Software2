#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
FILE *fp;

/* ファイルを開く */
fp = fopen("cpmdir1.bin", "br");

if (fp = NULL)
{
perror("file can't open.\n");
return -1;
}
else
{
printf("file open.\n");
}


fseek(fp, 10L, SEEK_SET);
printf("fp = %ld\n", ftell(fp));

return 0;
}
