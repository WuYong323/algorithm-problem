#include<stdio.h>

int main()
{
	int n;
	int p=0;
	scanf("%d",&n);
	int lst_reverse[6];
	while (n>0) {
		lst_reverse[p]=n%10;
		n/=10;
		p++;
	}
	int lst[p];
	for (int i=0;i<p;i++) {
		lst[p-1-i]=lst_reverse[i];
	}
	printf("%d\n",p);
	for (int i=0;i<p;i++) {
		printf("%d",lst[i]);
	}
	printf("\n");
	for (int i=0;i<p;i++) {
		printf("%d",lst_reverse[i]);
	}
	
	return 0;
}