#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int lst [m+1];
	for (int i=1;i<=m;i++) {
		cin>>lst[i];
	}
	for (int j=1;j<=m-1;j++){
		for (int i=1;i<=m-j;i++) {
			if (lst[i]>lst[i+1]) {
				int t;
				t=lst[i];
				lst[i]=lst[i+1];
				lst[i+1]=t;
			}
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<lst[i]<<" ";
	}
	return 0;
}