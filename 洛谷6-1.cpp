#include<stdio.h>
#include<math.h>

int main()
{
	double x1,y1,x2,y2,x3,y3;
	scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
	double l1,l2,l3;
	l1=pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
	l2=pow(pow(x3-x1,2)+pow(y3-y1,2),0.5);
	l3=pow(pow(x3-x2,2)+pow(y3-y2,2),0.5);
	printf("%.2f",l1+l2+l3);
	return 0;
}