#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int lst[n+1];
	for (int i=1;i<=n;i++) {
		cin>>lst[i];
	}
	for (int k=n/2;k>=1;k/=2){
		for (int i=k+1;i<=n;i++) {
			int t=lst[i];
			int j;
			for (j=i;j>=k+1 && lst[j-k]>t;j-=k){
				lst[j]=lst[j-k];
			}
			lst[j]=t;
		}
	}
	for (int i=1;i<=n;i++) {
		cout<<lst[i]<<" ";
	}
	return 0;
}