#include<stdio.h>

int main()
{
	int n,a,p;
	scanf("%d",&n);
	int q=0;
	p=0;
	int d;
	int i=1;
	for (i;i<=n;i++) {
		scanf("%d",&a);
		if(i==1) {
			d=a-1;
		}
		if(a!=d+1 && p==1 &&i!=2 &&d!=a){
			d=a-1;
		}
		if(a==d+1){
			q++;
			d=a;
		}
		else{
			q=1;
			d=a;
		}
		if(q>p){
			p=q;
		}
	}
	printf("%d",p);
	return 0;
}