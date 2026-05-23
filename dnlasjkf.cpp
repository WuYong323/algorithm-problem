#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int main()
{
	int t=1013;
	int k=2025;
	int ans1=1;
	int ans2=2026;
	while(t--){
		ans1=(ans1*4)%mod;
	}
	while(k--){
		ans2=(ans2*2)%mod;
	}
	cout<<ans1<<endl;
	cout<<ans2;
	return 0;
}