#include<stdio.h>
#include<string.h>
int main()
{
	char lst[200];
	scanf("%s",lst);
	int n=strlen(lst);
	for (int i=0;i<n;i++) {
		int s=(int)lst[i];
		if(s>=97 && s<=122) {
			lst[i]=(char)(s-32);
		}
	}
	for (int i=0;i<n;i++) {
		printf("%c",lst[i]);
	}
	return 0;
}