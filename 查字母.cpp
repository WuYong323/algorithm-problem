#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct point{
	int a;
	int b;
	int cha;
} Point;

void fun(char *lst){
	int p=1;
	Point pp[100];
	pp[1].a=0;
	for(int i=0;i<strlen(lst);i++){
		if(lst[i]==' '){
			pp[p].b=i-1;
			pp[p].cha=pp[p].b-pp[p].a;
			p++;
			pp[p].a=i+1;
		}
	}
	pp[p].b=strlen(lst)-1;
	pp[p].cha=pp[p].b-pp[p].a;
	p++;
	int t=0;
	int z;
	for(int i=1;i<p;i++){
		if(t<pp[i].cha){
			t=pp[i].cha;
			z=i;
		}
	}
	for(int i=pp[z].a;i<=pp[z].b;i++){
		printf("%c",lst[i]);
	}
	return;
}

int main()
{
	char lst[100];
	scanf("%[^\n]",lst);
	fun(lst);
	return 0;
}