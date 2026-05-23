#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<vector<ll>,ll> memo;

ll shu (ll a,ll b,ll c){
	vector<ll> lst={a,b,c};
	if(memo.find(lst)!=memo.end()){
		return memo[lst];
	}
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	else if(a>20||b>20||c>20){
		memo[lst]=shu(20,20,20);
		return memo[lst];
	}
	else if(a<b && b<c){
		memo[lst]=shu(a,b,c-1)+shu(a,b-1,c-1)-shu(a,b-1,c);
		return memo[lst];
	}
	else {
		memo[lst]=shu(a-1,b,c)+shu(a-1,b-1,c)+shu(a-1,b,c-1)-shu(a-1,b-1,c-1);
		return memo[lst];
	}
}
int main()
{
	ll a,b,c;
	while (cin>>a>>b>>c){
		if(a!=-1||b!=-1||c!=-1)
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<shu(a,b,c)<<endl;
	}
	return 0;
}