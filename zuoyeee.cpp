#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int n;
    char a[10][10]={"旺财","林冲","宋江","刘备","曹操","朱元璋","秦始皇","贾宝玉","李世民","慈禧"};
    srand((unsigned)time(NULL));
    n=rand()%10;
    printf("%s",a[n]);
    return 0;
 }