#include<bits/stdc++.h>
#define N 20004
using namespace std;

int n;
int l[N],r[N];
int f[N][2];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>l[i]>>r[i];
	}
	f[1][0]=abs(1-r[1])+(r[1]-l[1]);
	f[1][1]=abs(1-l[1])+(r[1]-l[1]);
	for(int i=2;i<=n;++i){
		f[i][0]=min(f[i-1][0]+abs(l[i-1]-r[i])+r[i]-l[i]+1,f[i-1][1]+abs(r[i-1]-r[i])+r[i]-l[i]+1);
		f[i][1]=min(f[i-1][0]+abs(l[i-1]-l[i])+r[i]-l[i]+1,f[i-1][1]+abs(r[i-1]-l[i])+r[i]-l[i]+1);
	}
	cout<<min(f[n][0]+n-l[n],f[n][1]+n-r[n]);
	return 0;
}