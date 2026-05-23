#include<bits/stdc++.h>
#define N 500005
#define ll long long
using namespace std;

int n,l,q;
ll is[N];

int main()
{
	cin>>n>>l>>q;
	int p,s;
	for(int i=1;i<=l;++i){
		cin>>p>>s;
		p-s>=1?is[p-s]++:is[1]++;
		p+s+1<=n?is[p+s+1]--:is[n];
	}
	for(int i=1;i<=n;++i){
		is[i]=is[i]+is[i-1];
	}
	int ans;
	for(int i=1;i<=q;++i){
		cin>>ans;
		if(is[ans]) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	return 0;
}