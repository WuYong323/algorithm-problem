#include<stdio.h>

int s_strlen(char a[]){
	int i=0;
	while(a[i]!=0){
		i++;
	}
	return i;
}

int main()
{
	char lst[100]={"abcdefg"};
	printf("%d",s_strlen(lst));
	return 0;
}