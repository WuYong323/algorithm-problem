#include<stdio.h>
#include<string.h>
int main()
{
	char lst[300];
	scanf("%s",lst);
	int n=strlen(lst);
	int p=0;
	int q=0;
	for (int i=0;i<n;i++) {
		if(lst[i]=='b' && lst[i+1]=='o' && lst[i+2]=='y') {
			p++;
			lst[i]='x';
			lst[i+1]='x';
			lst[i+2]='x';
		}
		if (lst[i]=='g' && lst[i+1]=='i' && lst[i+2]=='r' && lst[i+3]=='l') {
			q++;
			lst[i]='x';
			lst[i+1]='x';
			lst[i+2]='x';
			lst[i+3]='x';
		}
	}
	for (int i=0;i<n;i++) {
		if (lst[i]=='b' && lst[i+1]=='o' || lst[i]=='o' && lst[i+1]=='y') {
			p++;
			lst[i]='x';
			lst[i+1]='x';
		}
		if (lst[i]=='g' && lst[i+1]=='i' && lst[i+2]=='r' || lst[i]=='i' && lst[i+1]=='r' && lst[i+2]=='l') {
			q++;
			lst[i]='x';
			lst[i+1]='x';
			lst[i+2]='x';
		}
	}
	for (int i=0;i<n;i++) {
		if (lst[i]=='b' || lst[i]=='o' || lst[i]=='y') {
			p++;
		}
		if (lst[i]=='g' && lst[i+1]=='i' || lst[i]=='i' && lst[i+1]=='r' || lst[i]=='r' && lst[i+1]=='l') {
			q++;
			lst[i]='x';
			lst[i+1]='x';
		}
	}
	for (int i=0;i<n;i++) {
		if (lst[i]=='g' || lst[i]=='i' || lst[i]=='r' || lst[i]=='l') {
			q++;
		}
	}
	printf("%d\n%d",p,q);
	return 0;
}