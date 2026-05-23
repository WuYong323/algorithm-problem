#include<stdio.h>
#include<string.h>

int main()
{
	char a[200][200];
	scanf("%s",&a[0]);
	int n=strlen(a[0]);
	for (int i=1;i<n;i++) {
		for (int j=0;j<n;j++) {
			scanf("%s",&a[i][j]);
		}
	}
	printf("%d",n);
	char lst[40000];
	int p=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			lst[p]=a[i][j];
			p++;
		}
	}
	int count=0;
	for(int i=0;i<n*n;i++) {
		if(lst[i]==lst[i+1]) {
			count++;
		}
		else {
			printf("%d",count);
			count=0;
		}
	}
	return 0;
}