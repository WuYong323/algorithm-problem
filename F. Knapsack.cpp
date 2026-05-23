#include<bits/stdc++.h>
#define int long long
#define N 6000005
#define mod 998244353
using namespace std;

int n,m;
vector<pair<int,int>> v(N);

int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void solve(){
	map<int,int> mp;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int a,b;
		cin>>a>>b;
		mp[b]+=a;
	}
	int idx=0;
	for(auto i:mp){
		if(i.second>m){
			int sub=i.second-m;
			mp[i.first]-=sub;
			if(sub&1){
				sub++;
				mp[i.first]--;
			}
			mp[i.first+1]+=sub/2;
		}
		if(mp[i.first]){
			v[++idx]={i.first,mp[i.first]};
		}
	}
	int pre=-1,res=0,fu=0;
	for(int i=idx;i>=1;--i){
		if(pre==-1){
			res+=qmi(2,v[i].first);
			fu=m-v[i].second;
		}
		else{
			if(fu&&pre-v[i].first>40){
				cout<<res<<endl;
				return;
			}
			else{
				if(fu){
					for(int j=pre;j>v[i].first;j--){
						fu*=2;
						if(fu>2*m){
							cout<<res<<endl;
							return;
						}
					}
				}
				if(fu>=v[i].second) fu-=v[i].second;
				else{
					v[i].second-=fu;
					res=res+qmi(2,v[i].first);
					res%=mod;
					fu=m-v[i].second;
				}
			}
		}
		pre=v[i].first;
	}
	cout<<res<<endl;
}

signed main()
{
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}