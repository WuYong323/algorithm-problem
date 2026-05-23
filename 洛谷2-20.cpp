#include<stdio.h>

int main()
{
	int n,x,i,num;
	int n1=0;
	scanf("%d %d",&n,&x);
	for (i=1;i<=n;i++) {
		num=i;
		while (num>0) {
			int d=num%10;
			if (d==x) {
				n1++;
			}
			num/=10;
		}
	}
	printf("%d",n1);
	return 0;
}