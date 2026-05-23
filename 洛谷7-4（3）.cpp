#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	int a1[550],b1[550],c[550]={0};
	cin>>a>>b;
	int t=max(a.size(),b.size());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<b.size();i++) {
		b1[i]=b[i]-'0';
	}
	for (int i=0;i<a.size();i++) {
		a1[i]=a[i]-'0';
	}
	for (int i=0;i<t;i++) {
		c[i]+=a1[i]+b1[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	if(c[t])t++;
	for (int i=t-1;i>=0;i--) {
		cout<<c[i];
	}
	return 0;
}