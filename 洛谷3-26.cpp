#include <stdio.h>

int main()
{
	int i,s,p,q;
	int d=0;
	int j=13;
	int c=0;
	for (i=1;i<=12;i++) {
		scanf("%d",&s);
		if(300+d-s<0 && i<j){
			j=i;
		}
		else {
			p=(300+d-s)/100;
	    	q=300+d-s-100*p;
	    	c+=p;
	    	d=q;
		}
	}
	if(j>0 && j!=13) {
		printf("-%d",j);
	}
	else {
		printf("%.0f",c*100*1.2+q);
	}
	return 0;
}