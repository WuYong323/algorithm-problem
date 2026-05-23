#include<stdio.h>

int main()
{
	printf("BMI计算机\n\n");
	double weight,hight;
	printf("请输入你的体重(kg)：");
	scanf("%lf",&weight);
	printf("请输入你的身高(cm)：");
	scanf("%lf",&hight);
	double bmi=weight/(hight*hight)*10000;
	printf("您的bmi值为：%.2f\n",bmi);
	if (bmi<18.5) {
		printf("偏瘦，多吃点");
	}
	if(bmi>=18.8 && bmi<24.9) {
		printf("完美bmi值，继续保持");
	}
	if(bmi>=24.9 && bmi<29.9) {
		printf("超重，要注意");
	}
	if(bmi>=29.9) {
		printf("肥胖，要自律减肥；");
	}
	return 0;
}