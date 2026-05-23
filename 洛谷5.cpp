#include<stdio.h>

int main()
{
	char str;
	int i,j;
	str=getchar();
	for (i=1; i<=3;i++){
		for (j=1; j<=3-i;j++){
			printf(" ");
		}
		for (j=1; j<=2*i-1;j++){
			printf("%c",str);
		}
		printf("\n");
	}
	return 0;
}