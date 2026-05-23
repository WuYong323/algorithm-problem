#include<bits/stdc++.h>
#define ll long long
using namespace std;

double a,b;
ll ans;

int main()
{
	cin>>a>>b;
	for(int i=0;i<a;++i){
		ll num=2*a*b-a-b-2*b*i;
		if(num<0) break;
		ll y=num/(2*a);
		ans+=y+1;
	}
	cout<<ans;
	return 0;
}