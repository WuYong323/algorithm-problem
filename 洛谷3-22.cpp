#include<stdio.h>

int zhishu(int i)
{
	if (i<2) {
		return 0;
	}
	for (int j=2;j*j<=i;j++){
		if (i%j==0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	int d=0;
	int l;
	scanf("%d",&n);
	for (int k=2;k<=n;k++){
		if (zhishu(k)) {
			if(n%k==0){
				d=n/k;
				break;
			}
		}
	}
	printf("%d",d);
	return 0;
}