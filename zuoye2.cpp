#include<stdio.h>

int main()
{
	double x;
	scanf("%lf",&x);
	if(x<1) {
		printf("%f",x);
	}
	else if(x>=1 && x<10) {
		printf("%f",2*x-1);
	}
	else {
		printf("%f",3*x-11);
	}
	return 0;
}