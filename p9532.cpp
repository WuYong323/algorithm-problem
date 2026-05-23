#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans;

void solve(){
	int n,x;
	cin>>n>>x;
	if(x%2) ans=x*pow(2,(n-2));
	else{
		int tx=x,sum=2;
		while(!(tx%2)&&sum<n){
			tx/=2;
			++sum;
		}
		ans=tx*pow(2,(n-2));
	}
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}