#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	printf("余某猜数游戏\n\n\n");
	srand((unsigned)time(NULL));
	int a,b;
	int t=0;
	int p=1;
	a=rand()%100;
	while(p==1){
		printf("我已经想好了1-99的数，来猜吧！\n");
		for (int i=1;i<=7;i++) {
			scanf("%d",&b);
			if(a==b) {
				break;
			}
			else if (b>a) {
				printf("大了\n");
			}
			else{
				printf("小了\n");
			}
			t++;
		}
		if(t==7) {
			printf("一般\n");
		}
		else if(t==6) {
			printf("优秀\n");
		}
		else if (t<=5){
			printf("天才\n");
		}
		printf("你还想再玩吗？\n");
		scanf("%d",&p);
	}
	return 0;
}