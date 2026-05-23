#include<stdio.h>

void nixu(int lst[],int n){
	int *l=lst+1;
	int *r=lst+n;
	while(l<r){
		int temp=*l;
		*l=*r;
		*r=temp;
		l++;
		r--;
	}
	return;
}

int main()
{
	int n;
	int lst[100];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&lst[i]);
	}
	nixu(lst,n);
	for(int i=1;i<=n;i++){
		printf("%d ",lst[i]);
	}
	return 0;
}