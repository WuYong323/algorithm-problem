#include<bits/stdc++.h>
using namespace std;

int x;

int main()
{
	cin>>x;
	int len=0;
	int ans=0;
	int t=x;
	while(t>0){
		len++;
		t/=10;
	}
	int mod1=pow(10,len-1);
	int mod2=pow(10,len-2);
	ans+=x%mod1;
	x/=mod1;
	if(x!=1){
		ans+=mod1+1;
	}
	else{
		ans+=mod2+1;
	}
	cout<<ans;
	return 0;
}