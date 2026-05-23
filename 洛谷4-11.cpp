#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int lst[n];
	int num[n];
	for (int i=0;i<n;i++) {
		scanf("%d",&lst[i]);
	}
	for (int j=0;j<n;j++) {
		num[j]=lst[j];
	}
	int count=0;
	for(int i=0;i<n;i++) {
		for (int k=0;k<n;k++) {
			for (int l=0;l<n && l!=k;l++) {
				if (lst[i]==lst[k]+lst[l] && num[i]==lst[i]) {
					count++;
					num[i]++;
					
				}
			}
		}
	}
	printf("%d",count);
	return 0;
}