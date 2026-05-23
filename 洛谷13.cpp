#include<stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if (d-b>0) {
		printf("%d %d",c-a,d-b);
	}
	else {
		printf("%d %d",c-a-1,60+d-b);
	}
	return 0;
}