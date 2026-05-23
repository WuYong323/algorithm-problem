#include<stdio.h>

int main()
{
	int a,b,c,d,e;
	int count=0;
	int num=0;
	printf("你是否想变有钱：是输入1 or 否输入0\n");
	scanf("%d",&a);
	printf("你是否想变的很帅：是输入1 or 否输入0\n");
	scanf("%d",&b);
	printf("你是否想变得有魅力：是输入1 or 否输入0\n");
	scanf("%d",&c);
	printf("你是否想变的聪明：是输入1 or 否输入0\n");
	scanf("%d",&d);
	printf("你是否想拥有好运：是输入1 or 否输入0\n");
	scanf("%d",&e);
	if (a==1) {
		count+=20;
	}
	else{
		num+=20;
	}
	if (b==1) {
		count+=20;
	}
	else{
		num+=20;
	}
	if (c==1) {
		count+=20;
	}
	else{
		num+=20;
	}
	if (d==1) {
		count+=20;
	}
	else{
		num+=20;
	}
	if (e==1) {
		count+=20;
	}
	else{
		num+=20;
	}
	printf("你的贪心值为：%d,你的廉洁值为：%d\n",count,num);
	if (count>80) {
		printf("太贪婪了");
	}
	else if(count>60) {
		printf("小贪，要注意");
	}
	else if(count>20) {
		printf("刚刚好");
	}
	else {
		printf("太廉洁了");
	}
	return 0;
}