#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char lst[200];
	scanf("%s",lst);
	int p=0;
	int q=0;
	for (int i=0;i<n;i++) {
		if (lst[i]=='V' && lst[i+1]=='K') {
			p++;
			lst[i]='x';
			lst[i+1]='x';
		}
	}
	for (int i=0;i<n;i++) {
		if(lst[i]==lst[i+1] && lst[i]!='x') {
			q++;
		}
	}
	if(q>0) {
		p++;
	}
	printf("%d",p);
	return 0;
}