#include<stdio.h>

int main()
{
	int sum=0;
	for (int i=1;i<=50;i++){
		sum+=i*2-1;
	}
	printf("%d",sum);
	return 0;
}