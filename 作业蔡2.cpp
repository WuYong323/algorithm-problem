#include<stdio.h>
#include<math.h>

int main()
{
	int n=100;
	int lst[3];
	do {
		int i=0;
		int t=n;
		do {
			lst[i]=t%10;
			t/=10;
			i++;
		}while (t>0);
		int p=pow(lst[0],3)+pow(lst[1],3)+pow(lst[2],3);
		if (n==p) {
			printf("%d\t",n);
		}
		n++;
	}while (n<1000);
	return 0;
}