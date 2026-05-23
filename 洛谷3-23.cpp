#include<stdio.h>

int main()
{
	int n;
	int p=0;
	int q=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++){
			p++;
			printf("%02d",p);
		}
		printf("\n");
	}
	printf("\n");
	for (int a=1;a<=n;a++){
		for (int b=1;b<=n-a;b++){
			printf("  ");
		}
		for (int c=1;c<=a;c++){
			q++;
			printf("%02d",q);
		}
		printf("\n");
	}
	return 0;
}