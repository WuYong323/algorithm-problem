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
	for (int i=1;i<m;i++) {
		for (int j=i;j<=m;j++){
			if(lst[i]>lst[j]){
				int t=lst[i];
				lst[i]=lst[j];
				lst[j]=t;
			}
		}
	}
	for (int i=1;i<=m;i++) {
		cout<<lst[i]<<" ";
	}
	return 0;
}