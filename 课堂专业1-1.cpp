#include<stdio.h>

int main()
{
	char str1[100],str2[100],str3[100],str4[100];
	printf("name:");
	scanf("%s",&str1);
	printf("qq:");
	scanf("%s",&str2);
	printf("tel:");
	scanf("%s",&str3);
	printf("个人标签:");
	scanf("%s",&str4);
	printf("\n\n\n*********************************\n*name：\t\t%s\t\t*\n*qq:\t\t%s\t\t*\n*tel:\t\t%s\t\t*\n*个人标签：\t%s\t\t*\n*********************************",str1,str2,str3,str4);
	return 0;
}