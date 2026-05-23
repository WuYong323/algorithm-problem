#include<stdio.h>

int mul(){
	static int m=0;
	static int r=1;
	m++;
	r*=m;
	return r;
}


int main()
{
	int mu;
	for(int i=1;i<=5;i++){
		mu=mul();
	}
	printf("%d",mu);
	return 0;
}