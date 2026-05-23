#include<stdio.h>
#include<math.h>
int main()
{
	for (int i=1000;i<=9999;i++) {
		if(i==pow(i%10,4)+pow(i%100/10,4)+pow(i%1000/100,4)+pow(i/1000,4)){
			printf("%d   ",i);
		}
	}
	return 0;
}