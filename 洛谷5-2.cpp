#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	char lst[60];
	scanf("%s",lst);
	int p=strlen(lst);
	for (int i=0;i<p;i++) {
		int s=lst[i];
		int t=s+n;
		if(t>122) {
			t=t%123+97;
		}
		lst[i]=(char)t;
	}
	for (int i=0;i<p;i++) {
		printf("%c",lst[i]);
	}
	return 0;
}