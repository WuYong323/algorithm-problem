#include<stdio.h>

int zhishu(int a)
{
	if(a<=1){
		return 0;
	}
	for (int i=2;i*i<=a;i++) {
		if(a%i==0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n/2;i++) {
		int t=10000;
		for (int j=2;j<=n/2;j++) {
			if(zhishu(j)==1 && zhishu(2*i-j)==1 && t>j) {
				t=j;
			}
		}
		printf("%d=%d+%d\n",2*i,t,2*i-t);
	}
	return 0;
}