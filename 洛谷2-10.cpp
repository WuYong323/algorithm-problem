#include<stdio.h>

int main()
{
	int a,b,c,j;
	int d=8;
	int day=0;
	for (j=1;j<=7;j++) {
		scanf("%d %d",&a,&b);
		c=a+b;
		if (c>d) {
			d=c;
			day=j;
		}
	}
	printf("%d",day);
	return 0;
}