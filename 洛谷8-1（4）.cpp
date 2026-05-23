#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int lst[m+1];
	for (int i=1;i<=m;i++) {
		cin>>lst[i];
	}
	for (int k=m/2;k>=1;k/=2){
		for (int i=k+1;i<=m;i++) {
			int t=lst[i];
			int j;
			for (j=i;j>=k+1&&lst[j-k]>t;j-=k){
				lst[j]=lst[j-k];
			}
			lst[j]=t;
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<lst[i]<<" ";
	}
	return 0;
}