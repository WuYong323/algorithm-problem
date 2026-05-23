#include<stdio.h>
#include<string.h>

int main()
{
	double a;
	char str[0];
	scanf("%lf",&a);
	sprintf(str,"%.1f",a);
	int start=0,end= strlen(str)-1;
	while (start<end) {
		char str1=str[start];
		str[start]=str[end];
		str[end]=str1;
		start++;
		end--;
	}
	printf("%s",str);
	return 0;
}