#include<stdio.h>
#include<string.h>
int main()
{
	char lst[10];
	fgets(lst,sizeof(lst),stdin);
	int n=strlen(lst);
	int p=0;
	for (int i=0;i<n-1;i++) {
		if (lst[i]==' ') {
			p++;
		}
	}
	n=n-1-p;
	printf("%d",n);
	return 0;
}