#include<stdio.h>

typedef struct Student{
	int id;
	int score;
	int sztzscore;
	int zhscore;
}Student,stu; 

void tell(Student stu)
{
	if(stu.score+stu.sztzscore>140 && stu.zhscore>=800){
		printf("Excellent\n");
	}
	else{
		printf("Not excellent\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	char lst[n][3];
	for (int i=0;i<n;i++) {
		scanf("%d %d %d",&lst[i][0],&lst[i][1],&lst[i][2]);
	}
	for (int j=0;j<n;j++) {
		Student stu={lst[j][0],lst[j][1],lst[j][2],lst[j][1]*7+3*lst[j][2]};
		tell(stu);
	}
	return 0;
}