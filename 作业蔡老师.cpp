#include<stdio.h>

void space(int a){
	while(--a>=0){
		printf(" ");
	}
}


int main()
{
	space(50);
	printf("********************\n");
	space(50);printf("*");space(18);printf("*\n");
	space(50);printf("*");space(18);printf("*\n");
	space(50);printf("*");space(18);printf("*\n");
	space(50);printf("*");space(18);printf("*\n");
	space(50);printf("*");space(18);printf("*\n");
	space(50);
	printf("********************");
	return 0;
}