#include<stdio.h>
#include<string>

void s_strcat(char a[],char b[]){
	int t=strlen(a);
	for(int i=t;i<=t+strlen(b)-1;i++){
		a[i]=b[i-t];
	}
}

int main()
{
	char lst1[100]={"abbcccdddd"};
	char lst2[100]={"12345678"};
	s_strcat(lst1,lst2);
	printf("%s",lst1);
	return 0;
}