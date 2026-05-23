#include<bits/stdc++.h>
#define ll long long
using namespace std;

int q;
ll l,r;

int main()
{
	cin>>q;
	for(int i=1;i<=q;++i){
		cin>>l>>r;
		ll cnt=(r-l+1)%9;
		ll ans=cnt*(l%9)%9+cnt*(cnt-1)%9*5%9;
		cout<<ans%9<<<endl;
	}
	return 0;
}