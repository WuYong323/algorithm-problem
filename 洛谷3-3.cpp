#include<stdio.h>

int main()
{
	int k;
	scanf("%d",&k);
	double s=0.0;
	int i=1;
	while (s<=k) {
		s+=1.0/i;
		i++;
	}
	printf("%d",i-1);
	return 0;
}