#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	int num=0;
	int a,b,c;
	scanf("%d",&n);
	int lst[n][3];
	for (int i=0;i<=n-1;i++) {
		scanf("%d %d %d",&a,&b,&c);
		lst[i][0]=a;
		lst[i][1]=b;
		lst[i][2]=c;
	}
	for (int k=0;k<=n-1;k++) {
		for (int l=k+1;l<n;l++) {
			if (abs(lst[k][0]-lst[l][0])<=5 && 
			    abs(lst[k][1]-lst[l][1])<=5 && 
				abs(lst[k][2]-lst[l][2])<=5 && 
				abs(lst[k][0]+lst[k][1]+lst[k][2]-lst[l][0]-lst[l][1]-lst[l][2])<=10) {
				num++;
			}
		}
	}
	printf("%d",num);
	return 0;
}