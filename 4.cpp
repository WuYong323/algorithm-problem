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
	for(int i=100;i<1000;i++){
		if(shui(i)==1){
			printf("%d ",i);
		}
	}
	return 0;
}