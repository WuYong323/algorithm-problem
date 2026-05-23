#include<stdio.h>

int zhishu(int a) 
{
	for (int i=2;i*i<=a;i++) {
		if (a%i==0) {
			return 0;
		}
	}
	return 1;
}

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
	int a,b;
	scanf("%d %d",&a,&b);
	for (a;a<=b;a++) {
		if (huiwen(a)) {
			if(zhishu(a)){
				printf("%d\n",a);
			}
		}
	}
	return 0;
}