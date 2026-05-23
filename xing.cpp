#include<stdio.h>

int main()
{
	int i,j,p,q;
	int num;
	scanf("%d",&num);
	for (i=1; i<=num; i++) {
		for (j=1; j<=num-i; j++){
			printf(" ");
		}
		for (j=1; j<=2*i-1; j++){
			printf("*");
		}
		printf("\n");
	}
	for (p=1; p<=num-1; p++){
		for (q=1; q<=p; q++){
			printf(" ");
		}
		for (q=1; q<=2*(num-1-p)+1; q++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}