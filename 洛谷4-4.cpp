#include<stdio.h>

int main()
{
	int l,m;
	int num=0;
	int start,end; 
	scanf("%d %d",&l,&m);
	int lst[l+1];
    for (int i=0;i<=l;i++) {
    	lst[i]=1;
	}
	for (int i=1;i<=m;i++){
		scanf("%d %d",&start,&end);
		for (int j=start;j<=end;j++) {
			lst[j]=0;
		}
	}
	for (int i=0;i<=l;i++) {
		if (lst[i]==1) {
			num++;
		}
	}
	printf("%d",num);
	return 0;
}