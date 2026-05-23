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
	int a;
	scanf("%d",&a);
	printf("%d",fb(a));
	return 0;
}