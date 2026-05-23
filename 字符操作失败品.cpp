#include<stdio.h>
#include<string.h>

char num_1(char lst[],char lst1[])
{
	int a=strlen(lst);
	int b=strlen(lst1);
	for (int i=a;i<a+b;i++) {
		lst[i]=lst1[i-a];
	}
	for (int i=0;i<a+b;i++) {
		printf("%s",lst[i]);
	}
	return lst;
}

char num_2(char lst[],char lst1[])
{
	int a=lst[0]-'0';
	int b=lst1[2]-'0';
	for (int i=a;i<a+b;i++) {
		printf("%s",lst[i]);
	}
	return lst3;
}

char num_3(char lst[],char lst1[])
{
	int a=lst[0]-'0';
	
}

int main()
{
	int q;
	scanf("%d",&q);
	char lst[110];
	fgets(lst,sizeof(lst),stdin);
	char lst1[100];
	int p;
	for (int i=1;i<=q;i++) {
		scanf("%d %s",&p,lst1);
	}
	
	return 0;
}