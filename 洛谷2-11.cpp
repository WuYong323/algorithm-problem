#include<stdio.h>

int ma(int n,int a);

int ma(int n,int a)
{
	if (n%a==0) {
		return n/a;
	}
	else {
		return (n/a+1);
	}
}

int main()
{
	int n,a,b,j,price;
	int last=100000000;
	scanf("%d",&n);
	for (j=1; j<=3; j++) {
		scanf("%d %d",&a,&b);
		price=ma(n,a)*b;
		if (price<last) {
			last=price;
		}
	}
	printf("%d",last);
	return 0;
}