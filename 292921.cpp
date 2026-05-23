#include<stdio.h>

void sort(int *p,int n){
	int i,j,k;
	for(i=0;i<n;++i){
		k=i;
		for(j=i+1;j<n;++j){
			if(*(p+j)<*(p+k)) k=j;
		}
		if(k!=i){
			int t=*(p+k);
			*(p+k)=*(p+i);
			*(p+i)=t;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int lst[100];
	for(int i=0;i<n;++i){
		scanf("%d",&lst[i]);
	}
	int *p=lst;
	sort(p,n);
	for(int i=0;i<n;++i){
		printf("%d ",lst[i]);
	}
	return 0;
}