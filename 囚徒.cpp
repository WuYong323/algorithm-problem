#include<stdio.h>

int main()
{
	int lst[110];
	for(int i=1;i<=100;++i){
		lst[i]=i;
	}
	int t=1;
	while(100/num!=0){
		int num=1;
		for(int i=2;i<=100/num;i+=2){
			lst[t]=lst[i];
			t++;
		}
		num*=2;
	}
	printf("%d",lst[1]);
	return 0;
}