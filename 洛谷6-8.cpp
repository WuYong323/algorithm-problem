#include<stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	char lst[n][10];
	int a,b,c;
	int t=-1;
	int sum=0;
	int num,e,f,g;
	for (int i=0;i<n;i++) {
		scanf("%s %d %d %d",&lst[i],&a,&b,&c);
		sum=a+b+c;
		if(sum>t) {
			t=sum;
			e=a;
			f=b;
			g=c;
			num=i;
		}
	}
	printf("%s %d %d %d",lst[num],e,f,g);
	return 0;
}