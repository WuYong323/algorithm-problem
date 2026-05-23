#include<stdio.h>

int main()
{
	int a[3][4]={1,2,3,4,5,6,7,8,9,12,234,34};
	int (*p)[4],i,j;
	p=a;
	scanf("%d %d",&i,&j);
	printf("%d",*(*(p+i)+j));
	return 0;
}