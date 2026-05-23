#include<stdio.h>

int judge(int a){
	return a%2;
}

int main()
{
	int a;
	while(true){
		scanf("%d",&a);
		if(judge(a)==0){
			printf("为偶数\n");
		}
		else{
			printf("为奇数\n");
		}
	}
	return 0;
}