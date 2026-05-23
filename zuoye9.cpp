#include<stdio.h>
#include<string>

void copy(char *a,char *b){
	int i;
	for(i=0;i<strlen(b);i++){
		a[i]=b[i];
	}
	a[i]=0;
}
int main()
{
	char a[30];
	char b[30];
	scanf("%s",b);
	copy(a,b);
	printf("%s",a);
	return 0;
}