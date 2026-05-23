#include<stdio.h>

int main()
{
	int lst[9];
	double lst1[9]={1.0,0.5,5.0,4.0,5.0,1.0,2.0,2.0,2.5};
	double gpa;
	double sum;
	double score;
	printf("\t大一绩点计算器\n");
	printf("本学期共有9门必修课，请输入各科成绩\n\n\n");
	printf("请输入《学科前沿讲座》（学分1.0）成绩：");
	scanf("%d",&lst[0]);
	printf("请输入《形式与政策1》（学分0.5）成绩：");
	scanf("%d",&lst[1]);
	printf("请输入《大学英语-上》（学分5.0）成绩：");
	scanf("%d",&lst[2]);
	printf("请输入《高等数学B-上》（学分4.0）成绩：");
	scanf("%d",&lst[3]);
	printf("请输入《计算机导论与程序设计基础》（学分5.0）成绩：");
	scanf("%d",&lst[4]);
	printf("请输入《体育》（学分1.0）成绩：");
	scanf("%d",&lst[5]);
	printf("请输入《军事理论》（学分2.0）成绩：");
	scanf("%d",&lst[6]);
	printf("请输入《大学英语听说-上》（学分2.0）成绩：");
	scanf("%d",&lst[7]);
	printf("请输入《中国近代史纲要》（学分2.5）成绩：");
	scanf("%d",&lst[8]);
	for (int i=0;i<9;i++) {
		sum+=(lst[i]-50)/10*lst1[i];
		score+=lst1[i];
	}
	gpa=sum/score;
	printf("\n\n大一总GPA：%.2f",gpa);
	if(gpa>=4) {
		printf("优秀，继续保持");
	}
	else if(gpa>3.5) {
		printf("良好，争取更进一步");
	}
	else if (gpa>3) {
		prsintf("普通，加油");
	}
	else if (gpa>2){
		printf("及格");
	}
	else{
		printf("不及格");
	}
	return 0;
}