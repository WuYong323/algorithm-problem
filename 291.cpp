#include<stdio.h>

int lst[15];

void read(){
	for(int i=1;i<=10;++i){
		scanf("%d",&lst[i]);
	}
}

void fun(){
	int i=1,a=1;
	for(int j=2;j<=10;++j){
		if(lst[j]<lst[i]){
			i=j;
		}
		if(lst[j]>lst[a]){
			a=j;
		}
	}
	int temp=lst[1];
	lst[1]=lst[i];
	lst[i]=temp;
	temp=lst[10];
	lst[10]=lst[a];
	lst[a]=temp;
}

void put(){
	for(int i=1;i<=10;++i){
		printf("%d ",lst[i]);
	}
}

int main()
{
	read();
	fun();
	put();
	return 0;
}