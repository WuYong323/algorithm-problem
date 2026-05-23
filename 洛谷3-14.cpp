#include<stdio.h>

int main()
{
	int n,a;
	int b=0;
	int c=1000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if (b<a){
			b=a;
		}
		if(c>a) {
			c=a;
		}
	}
	printf("%d",b-c);
	return 0;
}