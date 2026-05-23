#include<bits/stdc++.h>
using namespace std;

int used[10005];
int used1[10005];
int lst[10005];
int main()
{
	int n,m,p;
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>lst[i];
		p=lst[i];
		for (int j=1;j<=lst[i];j++) {
			p-=used[j];
		}
		used[lst[i]]=1;
		lst[i]=p-1;
	}
	lst[n]+=m;
	for(int k=1;k<n;k++) {
		if(lst[n+1-k]/k>=1){
			int t=lst[n+1-k]/k;
			lst[n+1-k]%=k;
			lst[n-k]+=t;
		}
	}
	for (int i=1;i<=n;i++) {
		lst[i]++;
		int b=lst[i];
		for (int j=1;j<=b;j++){
			b+=used1[j];
		}
		used1[b]=1;
		cout<<b<<" ";
	}
	
	return 0;
}