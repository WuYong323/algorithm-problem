#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int lst1[n+1][n+1];
	int lst[n+1][n+1]={0};
	int t=1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			lst[i][j]=t;
			t++;
		}
	}
	int x,y,r,z;
	for (int i=1;i<=m;i++) {
		cin>>x>>y>>r>>z;
		if (z==0) {
			for (int k=-r;k<=r;k++) {
				for (int l=-r;l<=r;l++) {
					lst1[x+k][y+l]=lst[x-l][y+k];
				}
			}
			for (int i=x-r;i<=x+r;i++) {
				for (int j=y-r;j<=y+r;j++) {
					lst[i][j]=lst1[i][j];
				}
			}
		}
		if (z==1) {
			for (int k=-r;k<=r;k++) {
				for (int l=-r;l<=r;l++) {
					lst1[x+k][y+l]=lst[x+l][y-k];
				}
			}
			for (int i=x-r;i<=x+r;i++) {
				for (int j=y-r;j<=y+r;j++) {
					lst[i][j]=lst1[i][j];
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			cout<<lst[i][j]<<" ";
		}
		printf("\n");
	}
	return 0;
}