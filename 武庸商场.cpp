#include<stdio.h>
#include<string.h>
#include<time.h>

int main()
{
	time_t c_time;
	time(&c_time);
	int password=123456;
	int password_react;
	char lst[10];
	char username[10]="ysq";
	do {
		printf("用户名:");
		scanf("%s",&lst);
		printf("密码:");
		scanf("%d",&password_react);
		if(strcmp(username,lst)!=0 || password!=password_react) {
			printf("密码或用户名错误\n\n");
		}
		else {
			break;
		}
	} while (1);
	printf("\n\n欢迎登录南疆武庸连锁商场收银系统\n\n");
	int n=1;
	char lst1[50][10];
	double unite_price[50];
	int number[50];
	double lst3[50];
	int t=0;
	double sum=0.0;
	printf("***************************************************************");
	while(n==1) {
		printf("\n继续输入 1 or 退出输入 0 \n");
		scanf("%d",&n);
		if(n==0) {
			break;
		}
		printf("\n商品名称:");
		scanf("%s",&lst1[t]);
		printf("单价:");
		scanf("%lf",&unite_price[t]);
		printf("数量:");
		scanf("%d",&number[t]);
		lst3[t]=number[t]*unite_price[t];
		sum+=number[t]*unite_price[t];
		t++;
	}
	
	printf("\n\n\n******************************************************************");
	for(int i=0;i<t;i++) {
		printf("\n商品名称:%s\t\t",lst1[i]);
		printf("单价：%.2f\t",unite_price[i]);
		printf("数量：%d\t\t",number[i]);
		printf("金额：%.2f\n",lst3[i]);
	}
	printf("\t\t\t\t\t\t\t总价：%.2f",sum);
	printf("\n******************************************************************");
	printf("\n\t\t时间：%s",asctime(localtime(&c_time)));
	printf("\t\t祝你购物愉快，欢迎下次光临！");
	return 0;
}