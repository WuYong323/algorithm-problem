#include<stdio.h>

int main()
{
	char lst1,lst2;
	int lst[3];
	for (scanf("%c:=%c;",&lst1,&lst2)==2) {
		if (lst1=='a') {
			lst[i]=lst2-'0';
		}
		if (lst1=='b') {
			lst[i]=lst2-'0';
		}
		if (lst1=='c') {
			lst[i]=lst2-'0';
		}
		if(lst2-'0'>9) {
			lst[i]=lst[lst2-'a'];
		}
	}
	printf("%d %d %d",lst[0],lst[1],lst[2]);
	return 0;
}