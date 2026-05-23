#include<stdio.h>
#include<string.h>

int main()
{
	int password=123456;
	int password_react;
	char lst[10];
	char username[10]="ysq";
	do {
		printf("username:");
		scanf("%s",&lst);
		printf("password:");
		scanf("%d",&password_react);
		if(strcmp(username,lst)!=0 || password!=password_react) {
			printf("error\n\n");
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
	int sum=0;
	printf("***********************************************");
	while(n==1) {
		printf("\n继续输入 1 or 退出输入 0 \n");
		scanf("%d",&n);
		if(n==0) {
			break;
		}
		printf("trade_name:");
		scanf("%s",&lst1[t]);
		printf("unite_price:");
		scanf("%lf",&unite_price[t]);
		printf("number:");
		scanf("%d",&number[t]);
		lst3[t]=number[t]*unite_price[t];
		sum+=number[t]*unite_price[t];
		t++;
	}
	
	printf("\n\n\n***********************************************");
	for(int i=0;i<t;i++) {
		printf("\n商品名称:%s\t",lst1[i]);
		printf("单价：%.2f\t",unite_price[i]);
		printf("数量：%d\t",number[i]);
		printf("金额：%f.2\n",lst[i]);
	}
	printf("总价：%d",sum);
	return 0;
}