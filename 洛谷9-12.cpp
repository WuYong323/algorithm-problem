#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int ma=1e6+10;
const ll Mod=1e9+7;
ll lst[ma],num[ma],n,sum,maxa;

long long c(ll x,ll k){
	return (k==1ll?x:x*(x-1ll)/2ll)%Mod;
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>lst[i];
		maxa=max(lst[i],maxa);
		num[lst[i]]++;
	}
	for (int i=2;i<=maxa;i++){
		ll t=c(num[i],2ll)%Mod;
		for (int j=1;j<=i/2;j++){
			if(j!=i-j&&num[j]>=1&&num[i-j]>=1){
				sum+=t*c(num[j],1)*c(num[i-j],1)%Mod;
			}
			if(j==i-j&& num[j]>=2){
				sum+=t*c(num[j],2)%Mod;
			}
			sum%=Mod;
		}
	}
	cout<<sum;
	return 0;
}