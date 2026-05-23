#include<stdio.h>
#include<string.h>

typedef struct Student{
	char name[20];
	int age;
	int score;
}Student;

Student stud(Student stu)
{
	Student stu1;
	stu1.age=stu.age+1;
	int t=stu.score/5*6;
	if(t>600) {
		t=600;
	}
	strcpy(stu1.name,stu.name);
	stu1.score=t;
	return stu1;
}

int main()
{
	int n;
	scanf("%d",&n);
	Student stu;
	int ag[n];
	int sc[n];
	char na[n][20]; 
	for (int i=0;i<n;i++) {
		scanf("%s %d %d",&stu.name,&stu.age,&stu.score);
		strcpy(na[i],stud(stu).name);
		ag[i]=stud(stu).age;
		sc[i]=stud(stu).score;
	}
	for (int j=0;j<n;j++) {
		printf("%s %d %d\n",na[j],ag[j],sc[j]);
	}
	return 0;
}