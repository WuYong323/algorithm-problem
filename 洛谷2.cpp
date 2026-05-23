#include<stdio.h>

int main()
{
	int i,j,p,q;
	for (i=1; i<=3; i++) {
		for (j=1; j<=3-i; j++){
			printf(" ");
		}
		for (j=1; j<=2*i-1; j++){
			printf("*");
		}
		printf("\n");
	}
	for (p=1; p<=2; p++){
		for (q=1; q<=p; q++){
			printf(" ");
		}
		for (q=1; q<=2*(2-p)+1; q++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}