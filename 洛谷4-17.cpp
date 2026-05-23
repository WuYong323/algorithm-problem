#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int lst[n][n];
	for (int h=0;h<n;h++) {
		for (int g=0;g<n;g++) {
			lst[h][g]=0;
		}
	}
	int x,y;
	for (int p=1;p<=m+k;p++) {
		scanf("%d %d",&x,&y);
		for (int i=-2;i<=2;i++) {
			for (int j=-2;j<=2;j++) {
				if(p<=m && abs(i)+abs(j)<=2) {
					lst[y-1+i][x-1+j]++;
				}
				if(p>m && abs(i)-abs(j)<=2) {
					lst[y-1+i][x-1+j]++;
				}
			}
		}
	}
	int count=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if(lst[i][j]==0) {
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}