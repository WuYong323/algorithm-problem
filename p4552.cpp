#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll c,p,q,a[100010];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		c=a[i]-a[i-1];
		if(c>0) p+=c;
		else q-=c;
	}
	ll ans1=max(p,q);
	ll ans2=abs(p-q)+1;
	cout<<ans1<<"\n"<<ans2;
	return 0;
}
