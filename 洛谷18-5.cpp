#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int main()
{
	int n;
	cin>>n;
	int lst[60];
	long long ans=1;
	for(int i=1;i<=n;++i){
		cin>>lst[i];
	}
	sort(lst+1,lst+1+n);
	for(int i=1;i<=n;++i){
		ans*=(lst[i]-i+1);
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
}