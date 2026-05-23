#include<stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	if (a<=150) {
		printf("%.1f",0.4463*a);
	}
	else if (a>=151 && a<=400) {
		printf("%.1f",0.4463*150+0.4663*(a-150));
	}
	else {
		printf("%.1f",0.4463*150+0.4663*250+0.5663*(a-400));
	}
	return 0;
}