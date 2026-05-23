#include<stdio.h>

int main()
{
	printf("大学生活动问答\n\n");
	printf("好输入y or 不好输入n\n");
	char a,b,c,d,e;
	printf("课程学习如何？\n");
	scanf("%c",&a);
	getchar();
	printf("锻炼身体吗？\n");
	scanf("%c",&b);
	getchar();
	printf("专业学习如何？\n");
	scanf("%c",&c);
	getchar();
	printf("有过社会实践吗？\n");
	scanf("%c",&d);
	getchar();
	printf("人际交往如何？\n");
	scanf("%c",&e);
	getchar();
	int count=0;
	if (a=='y') {
		count+=20;
	}
	if (b=='y') {
		count+=20;
	}
	if (c=='y') {
		count+=20;
	}
	if (d=='y') {
		count+=20;
	}
	if (e=='y') {
		count+=20;
	}
	printf("您的得分为：%d",count);
	return 0;
}