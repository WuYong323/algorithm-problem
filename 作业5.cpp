#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int n;
	printf("请随机输入一个一百以内的数：");
	scanf("%d",&n);
	srand((unsigned)time(NULL));
	int a,b,c,d,e;
	a=rand()%101;
	b=rand()%101;
	c=rand()%101;
	d=rand()%101;
	e=5*n-a-b-c-d;
	printf("\n\n五个随机数为：\t%d,%d,%d,%d,%d\n",a,b,c,d,e);
	printf("\n平均数=(%d+%d+%d+%d+%d)/5=%d",a,b,c,d,e,n);
	return 0;
}