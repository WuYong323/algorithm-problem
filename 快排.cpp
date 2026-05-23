#include<stdio.h>

int n;
int lst[10000];
void qsort(int l,int r){
	if(l>=r){
		return;
	}
	int i=l;
	int j=r;
	int mid=(r+l)/2;
	int p=lst[mid];
	while(i<=j){
		while(lst[i]<p)i++;
		while(lst[j]>p)j--;
		if(i<=j){
			int t=lst[i];
			lst[i]=lst[j];
			lst[j]=t;
			i++;
			j--;
		}
	}
	if(l<j) qsort(l,j);
	if(i<r) qsort(i,r);
}


int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&lst[i]);
	}
	qsort(1,n);
	for (int i=1;i<=n;i++){
		printf("%d",lst[i]);
	}
	return 0;
}