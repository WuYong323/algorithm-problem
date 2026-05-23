#include<stdio.h>

int main()
{
	int h,r;
	double num,pai;
	pai=3.14;
	scanf("%d %d",&h,&r);
    num=20000/(pai*r*r*h)+1;	
	printf("%.0f",num);
	return 0;
}