#include<stdio.h>
#include<string>

int lst[110];

int main()
{
	lst[49]=1,lst[50]=10,lst[51]=11,lst[52]=100;
	lst[53]=101,lst[54]=110,lst[55]=111;
	lst[56]=1000,lst[57]=1001,lst[97]=1010;
	lst[98]=1011,lst[99]=1100,lst[100]=1101;
	lst[101]=1110,lst[102]=1111;
	char str[]="余锶埼";
	char ss[10];
	printf("%d\n\n",sizeof(str));
	for(int i=0;i<sizeof(str);++i){
		printf("%c\n",str[i]);
		printf("%d\n",str[i]);
		printf("%x\n",str[0]);
		sprintf(ss,"%x\n",str[0]);
		for(int j=0;j<strlen(ss);++j){
			printf("%04d ",lst[ss[j]]);
		}
		printf("\n%p\n",&str[i]);
		printf("\n\n");
	}
	return 0;
}