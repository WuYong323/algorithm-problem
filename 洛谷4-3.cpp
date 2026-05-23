#include<stdio.h>

int main()
{
	int n,t;
	int num=1;
	scanf("%d",&n);
	t=n;
	while (t!=1) {
		if(t%2!=0) {
			t=t*3+1;
		}
		else {
			t/=2;
		}
		num++;
	}
	int lst[num];
	if (num==1) {
		lst[0]=1;
	}
	else {
		for (int i=num-2;i>=0;i--) {
			if (i==num-2) {
				lst[num-1]=n;
			}
			if (n%2==0) {
				n/=2;
				lst[i]=n;
			}
			else {
				n=n*3+1;
				lst[i]=n;
			}
	    }
	}
	for (int j=0;j<num;j++) {
		printf("%d ",lst[j]);
	}
	return 0;
}