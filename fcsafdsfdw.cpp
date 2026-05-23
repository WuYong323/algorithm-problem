#include<stdio.h>

int main()
{
	int lst[10];
	for(int i=1;i<=5;i++){
		scanf("%d",&lst[i]);
	}
	int i;
	for(i=1;i<=5;i++){
		int k=i,j;
		for(j=i+1;j<=5;j++){
			if(lst[k]>lst[j]){
				k=j;
			}
		}
		if(k!=i){
			int t=lst[k];
			lst[k]=lst[i];
			lst[i]=t;
		}
	}
	for(int i=1;i<=5;i++){
		printf("%d ",lst[i]);
	}
	return 0;
}