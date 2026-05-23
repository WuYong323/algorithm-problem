#include<stdio.h>

int zhishu(int a);

int zhishu(int a)
{
	if (a<2) {
		return 0;
	}
	for (int q=2;q*q<=a;q++) {
		if (a%q==0) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int l;
	scanf("%d",&l);
	int s=0;
	int i=0;
	int t=0;
	while (s<=l) {
		i++;
		if (zhishu(i)) {
			s+=i;
			if (s<=l){
				printf("%d\n",i);
			}
			t++;
		}
	}
	printf ("%d",t-1);
	return 0;
}