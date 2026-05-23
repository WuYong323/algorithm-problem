#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	for (int i=1;i<=9;i++) {
		for (int j=1;j<=i;j++) {
			printf("%dx%d=%d\t",j,i,i*j);
		}
		printf("\n");
	}
	for (int i=9;i>=1;i--) {
		for (int j=1;j<=i;j++) {
			printf("%dx%d=%d\t",j,i,i*j);
		}
		printf("\n");
	}
	return 0;
}