#include<stdio.h>
#include<string>
int cmp(char *a,char *b){
	for(int i=0;i<=strlen(a);i++){
		if(a[i]!=b[i]){
			return a[i]-b[i];
		}
	}
	return 0;
}

int main()
{
	char lst1[30];
	char lst2[30];
	scanf("%s",lst1);
	scanf("%s",lst2);
	int t=cmp(lst1,lst2);
	if(t==0){
		printf("相等");
	}
	else if(t>0){
		printf("大于");
	}
	else{
		printf("小于");
	}
	return 0;
}