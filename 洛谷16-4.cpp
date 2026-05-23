#include<bits/stdc++.h>
using namespace std;

map<string,int> memo;


int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		a=a.substr(0,2);
		if(a!=b){
			ans+=memo[a+b];
		}
		memo[b+a]++;
	}
	cout<<ans;
	return 0;
}