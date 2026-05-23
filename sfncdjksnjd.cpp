#include<stdio.h>
#include<stdlib.h>

void msort(int *a,int n){
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			if(*(a+j-1)<*(a+j)){
				int p=*(a+j-1);
				*(a+j-1)=*(a+j);
				*(a+j)=p;
			}
		}
	}
}



int main()
{
	int *p=(int *)malloc(5*sizeof(int));
	for(int i=1;i<=3;i++){
		scanf("%d",p+i-1);
	}
	msort(p,3);
	for(int i=1;i<=3;i++){
		printf("%d ",*(p+i-1));
	}
	return 0;
}