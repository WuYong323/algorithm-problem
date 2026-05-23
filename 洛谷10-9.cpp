#include<bits/stdc++.h>
using namespace std;

int f[1000010],g[1000010];


int main()
{
	int n;
	cin>>n;
	f[0]=1;
	g[0]=0;
	f[1]=g[1]=1;
	for(int i=2;i<=n;i++){
		g[i]=f[i-1]+g[i-1];
		f[i]=f[i-1]+f[i-2]+2*g[i-2];
		if(g[i]>=10000){
			g[i]%=10000;
		}
		if(f[i]>=10000){
			f[i]%=10000;
		}
	}
	cout<<f[n];
	return 0;
}