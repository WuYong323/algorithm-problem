#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	char lst[110][110];
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%s",lst[i][j]);
		}
		getchar();
	}
	for (int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if (lst[i][j]=='?') {
				lst[i][j]='0';
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			for (int k=-1;k<=1;k++) {
				for (int l=-1;l<=-1;l++) {
					if (lst[i][j]=='*' && lst[i+k][j+l]!='*') {
						lst[i+k][j+l]++;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cout<<lst[i][j];
		}
		printf("\n");
	}
	return 0;
}