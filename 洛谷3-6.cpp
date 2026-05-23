#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	int s=0;
	while (i<n) {
		i++;
		s+=i;
	}
	printf("%d",s);
	return 0;
}