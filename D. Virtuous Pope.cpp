#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a,b,c,n;
int x_1,x_2,y_1,y_2,z_1,z_2;
vector<pair<int,int>> sx,sy,sz;

int maxnum(vector<pair<int,int>>& s){
	vector<pair<int,int>> events;
	for(auto& t:s){
		events.emplace_back(t.first,1);
		events.emplace_back(t.second,-1);
	}
	sort(events.begin(),events.end(),[](auto& a,auto& b){
		if(a.first!=b.first) return a.first<b.first;
		return a.second>b.second;
	});
	int cur=0,ans=0;
	for(auto t:events){
		if(t.second==1){
			++cur;
			ans=max(ans,cur);
		}
		else{
			ans=max(ans,cur);
			--cur;
		}
	}
	return ans;
}

int main()
{
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;++i){
		cin>>x_1>>y_1>>z_1>>x_2>>y_2>>z_2;
		sx.emplace_back(min(x_1,x_2),max(x_1,x_2));
		sy.emplace_back(min(y_1,y_2),max(y_1,y_2));
		sz.emplace_back(min(z_1,z_2),max(z_1,z_2));
	}
	int ans=max({maxnum(sx),maxnum(sy),maxnum(sz)});
	cout<<ans;
	return 0;
}