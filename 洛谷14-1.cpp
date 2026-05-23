#include<bits/stdc++.h>
using namespace std;

int lst[2000020];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		cout<<lst[t]<<endl;
	}
	return 0;
}