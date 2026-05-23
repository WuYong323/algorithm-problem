#include<stdio.h>

int main()
{
	char *lst[20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	char **p=lst;
	int t;
	scanf("%d",&t);
	t--;
	while(t--){
		p++;
	}
	printf("%s",*p);
	return 0;
}
