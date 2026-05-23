#include<stdio.h>
#include<string.h>

int main()
{
	char lst1[20];
	char lst2[1000000];
	scanf("%s",lst1);
	scanf("%s",lst2);
	for (int i=0;i<strlen(lst1);i++) {
		if(lst1[i]-'a'<0) {
			lst1[i]+=32;
		}
	}
	for (int i=0;i<strlen(lst2);i++) {
		if(lst2[i]-'a'<0) {
			lst2[i]+=32;
		}
	}
	int m;
	if(strlen(lst2)%strlen(lst1)==0) {
		m=strlen(lst2)/strlen(lst1);
	}
	else {
		m=strlen(lst2)/strlen(lst1)+1;
	}
	int p=-1;
	int d;
	char *result=strstr(lst2,lst1);
	if(result!=NULL) {
		d=result-lst2;
		p=1;
	}
	while (result!=NULL) {
		int wei=result-lst2;
		int k=0;
		for (int l=wei;l<strlen(lst2);l++) {
			lst2[k]=lst2[l];
			lst2[strlen(lst2)-1-wei]="\0";
		}
		char *result=strstr(lst2,lst1);
		p++;
	}
	printf("%d %d",p,d);
	return 0;
}