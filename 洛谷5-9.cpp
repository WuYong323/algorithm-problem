#include<stdio.h>
#include<string.h>
int main()
{
	char lst1[10];
	char lst2[10];
	scanf("%s",lst1);
	scanf("%s",lst2);
	int n1=strlen(lst1);
	int n2=strlen(lst2);
	int a=1;
	int b=1;
	for (int i=0;i<n1;i++) {
		int z=lst1[i]-64;
		a*=z;
	}
	for (int i=0;i<n2;i++) {
		int m=lst2[i]-64;
		b*=m;
	}
	if (a%47==b%47) {
		printf("GO");
	}
	else {
		printf("STAY");
	}
	return 0;
}