#include<stdio.h>

void fm(int *a,int *b){
	int t=*a;
	if(t<*b){
		t=*b;
	}
	int p=*a;
	if(t>*b){
		p=*b;
	}
	*b=t;
	*a=p;
	
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	fm(&a,&b);
	printf("min=%d,max=%d",a,b);
	return 0;
}