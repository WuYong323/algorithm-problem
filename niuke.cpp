#include<bits/stdc++.h>
using namespace std;

char lst[1010][1010];
int lst1[1010];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			lst[i][j]='*';
		}
	}
	for(int i=1;i<=m;i++){
			lst1[i]=1;
		}
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		if(x>=lst1[y]){
		lst[lst1[y]][y]='.';
		lst1[y]+=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<lst[i][j];
		}
		cout<<endl;
	}
	return 0;
}