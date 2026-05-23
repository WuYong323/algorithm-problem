#include<stdio.h>

float average(float array[])
{
	int i;
	float aver,sum=array[0];
	for(i=1;i<10;i++){
		sum=sum+array[i];
	}
	aver=sum/10;
	return aver;
}

int main()
{
	int i;
	float score[10],aver;
	
	printf("input 10 scores:\n");
	for(i=0;i<10;i++){
		scanf("%f",&score[i]);
	}
	aver=average(score);
	printf("average score is %5.2f\n",aver);
	return 0;
}