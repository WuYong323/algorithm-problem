#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int main()
{
	int n;
	int a=4;
	scanf("%d",&n);
	while (n>=0) {
		for (int i=1;i<=a;i++){
			printf(" ");
		}
		printf("*\n");
		for (int i=1;i<=a+1;i++){
			printf(" ");
		}
		printf("*\n");
		for (int i=1;i<=a-4;i++) {
			printf(" ");
		}
		for (int i=1;i<=7;i++){
			printf("*");
		}
		for(int i=1;i<100-a;i++) {
			printf(" ");
		}
		printf("*");
		printf("\n");
		for (int i=1;i<=a+1;i++){
			printf(" ");
		}
		printf("*\n");
		for (int i=1;i<=a;i++){
			printf(" ");
		}
		printf("*\n");
		Sleep(200);
		system("cls");
		a++;
		n--;
	}
	
	return 0;
}