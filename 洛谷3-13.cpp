#include<stdio.h>

int fb(int a);

int fb(int a)
{
	if (a==1||a==2) {
		return 1;
	}
	return fb(a-1)+fb(a-2);
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%.2f",fb(n)/1.0);
	return 0;
}