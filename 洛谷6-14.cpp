#include<stdio.h>
#include<math.h>

int a[1100][1100];

void shemian(int p,int k,int l)
{
	if(p==2) {
		a[k][l]=0;
		return;
	}
	for (int i=k;i<=k+p/2-1;i++) {
		for (int j=l;j<=l+p/2-1;j++) {
			a[i][j]=0;
		}
	}
	shemian(p/2,k+p/2,l);
	shemian(p/2,k+p/2,l+p/2);
	shemian(p/2,k,l+p/2);
}

int main()
{
	int n;
	scanf("%d",&n);
	int p=pow(2,n);
	for (int i=1;i<=p;i++) {
		for (int j=1;j<=p;j++) {
			a[i][j]=1;
		}
	}
	shemian(p,1,1);
	for (int i=1;i<=p;i++) {
		for (int j=1;j<=p;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}