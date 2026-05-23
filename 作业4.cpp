#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	printf("运气查询器（1为极差，100为极好）\n\n\n");
	int n;
	srand((unsigned)time(NULL));
	printf("继续请按1 or 退出请按0\n");
	int t;
	scanf("%d",&t);
	if(t==0) {
		return 0;
	}
	else{
		n=rand()%101;
		printf("你的运气数为：%d",n);
	}
	if(n>=100) {
		printf("\n帝王之姿");
	}
	else if(n>=70) {
		printf("\n运气绝佳");
	}
	else if (n>=50) {
		printf("\n较佳，保守一点");
	}
	else {
		printf("\n诸事不宜");
		printf("\n天无绝人之路，只要我想走路就在脚下");
	}
	return 0;
}