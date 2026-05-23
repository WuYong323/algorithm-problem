#include<stdio.h>
#include<string>

int main()
{
	char a[30],b[30];
	scanf("%s",a);
	scanf("%s",b);
	int j=0;
	for (int i=strlen(a);i<=strlen(a)+strlen(b);i++){
		a[i]=b[j];
		j++;
	}
	printf("%s",a);
	return 0;
}