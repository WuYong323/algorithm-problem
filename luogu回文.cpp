#include<stdio.h>

int huiwen(int a)
{
	if(a<0) return 0;
	int temp=a;
	int reverse=0;
	while (temp>0) {
		reverse=reverse*10+temp%10;
		temp/=10;
	}
	return reverse==a;
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("%d",huiwen(a));
	return 0;
}