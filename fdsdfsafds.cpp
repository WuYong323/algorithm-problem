#include<stdio.h>
#include<math.h>
int shui(int a){
	int sum=0;
	int t=a;
	while(t>0){
		sum+=pow(t%10,3);
		t/=10;
	}
	if(sum==a){
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	printf("%d",shui(153));
	return 0;
}