#include<stdio.h>
#include<stdlib.h>

void xsort(int *a,int n){
	int i,j,k;
	for(i=1;i<=n;i++){
		k=i;
		for(j=i+1;j<=n;j++){
			if(*(a-1+k)>*(a-1+j)){
				k=j;
			}
		}
		if(k!=i){
			int p=*(a-1+k);
			*(a-1+k)=*(a-1+i);
			*(a-1+i)=p;
		}
	}
	return;
}

int main()
{
	int *p=(int *)malloc(3*sizeof(int));
	for(int i=1;i<=3;i++){
		scanf("%d",p+i-1);
	}
	xsort(p,3);
	for(int i=1;i<=3;i++){
		printf("%d ",*(p+i-1));
	}
	return 0;
}