#include<stdio.h>

int runnian(int a)
{
	if(a%400==0) {
		return 1;
	}
	if(a%100!=0 && a%4==0) {
		return 1;
	}
	return 0;
}

int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	int lst[y-x+1];
	int j=0;
	for (int i=x;i<=y;i++) {
		lst[j]=i;
		j++;
	}
	int count=0;
	for (int i=0;i<y-x+1;i++) {
		if(runnian(lst[i])==1) {
			count++;
		}
	}
	printf("%d\n",count);
	for (int i=0;i<y-x+1;i++) {
		if(runnian(lst[i])==1) {
			printf("%d ",lst[i]);
		}
	}
	return 0;
}