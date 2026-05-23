#include<stdio.h>

int zhishu(int a)
{
	if(a<=1) {
		return 0;
	}
	for(int i=2;i*i<=a;i++) {
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
	int lst[n];
	for (int i=0;i<n;i++) {
		scanf("%d",&lst[i]);
	}
	for (int j=0;j<n;j++) {
		if(zhishu(lst[j])==1) {
			printf("%d ",lst[j]);
		}
	}
	return 0;
}