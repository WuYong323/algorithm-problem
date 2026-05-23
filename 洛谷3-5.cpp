#include<stdio.h>

int main()
{
	int k,jb;
	int i=0;
	int s=0;
	int n=0;
	scanf("%d",&k);
	while (s<k) {
        i++;
		s+=i;
	}	
	for (int j=1;j<=i;j++) {
		n+=j*j;
	}
	jb=n-(s-k)*i;
	printf("%d",jb);
	return 0;
}