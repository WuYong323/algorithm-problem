#include<stdio.h>

int main()
{
	int a,b,c,d,b1,b2,b3,c1,c2,c3,c4,c5,last;
	char d1;
	scanf("%d-%d-%d-%c",&a,&b,&c,&d1);
	d=d1;
	if (d==88) {
		d=10;
	}
	b1=b%10;
	b2=(b%100)/10;
	b3=(b%1000)/100;
	c1=c%10;
	c2=(c%100)/10;
	c3=(c%1000)/100;
	c4=(c%10000)/1000;
	c5=(c%100000)/10000;
	last=(a+2*b3+3*b2+4*b1+5*c5+c4*6+7*c3+c2*8+c1*9)%11;
	if (last+48==d || last==d) {
		printf("Right");
	}
	else if(last==10) {
		printf("%d-%d-%d-X",a,b,c);
	}
	else {
		printf("%d-%d-%d-%d",a,b,c,last);
	}
	return 0;
}