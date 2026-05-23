#include<stdio.h>

double ave(double *lst){
	double sum=0;
	for(int i=1;i<=5;i++){
		sum+=lst[i];
	}
	return sum/=5;
}

int main()
{
	double lst[6];
	for(int i=1;i<=5;i++) {
		scanf("%lf",&lst[i]);
	}
	printf("%.3f",ave(lst));
	return 0;
}