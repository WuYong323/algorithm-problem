#include<stdio.h>

int main()
{
	int n,d,i;
	scanf("%d",&n);
	for (i=1;i;i++) {
		if((n-i*1092)%364==0 && (n-i*1092)/364<=100) {
			d=(n-i*1092)/364;
			break;
		}
    }
    printf("%d\n%d",d,i);
	return 0;
}