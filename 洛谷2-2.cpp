#include<stdio.h>

int main()
{
	int m,t,s;
	scanf("%d %d %d",&m,&t,&s);
	if (t==0){
		printf("0");
	}
	else if (s==0){
		printf("%d,m");
	}
	else if (m==0) {
		printf("0");
	}
	else if (m==0 && s==0) {
		printf("0");
	}
	else if (m==0 && t==0) {
		printf("0");
	}
	else if (s==0 && t==0) {
		printf("%d,m");
	}
	else if (m==0 && s==0 && t==0) {
		printf(0);
	}
	else {
		if (m-s/t>0){
			if (s%t==0) {
	            printf("%d",m-s/t);
            }
            else {
	            printf("%d",m-s/t-1);
            }
		}
		else {
			printf("0");
		}
		}
	return 0;
}