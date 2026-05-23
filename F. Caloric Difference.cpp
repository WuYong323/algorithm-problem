#include<bits/stdc++.h>
using namespace std;

int t,n,k;

void solve(){
	cin>>n>>k;
	double r0,c0,p,L,R;
	cin>>r0>>c0>>p>>L>>R;
	vector<double> r(n+1,0);
	while(k--){
		int id;
		double val;
		cin>>id>>val;
		r[id]=val;
	}
	double res=0;
	vector<double> c(n+1);
	c[0]=c0;
	r[0]=r0;
	for(int i=1;i<=n;++i){
		if(r[i]==0.0) r[i]=L;
		c[i]=p*c[i-1]+(1.0-p)*r[i-1];
		res+=c[i]-r[i];
	}
	printf("%.10f\n",res);
}

int main()
{
	cin>>t;
	while(t--) solve();
	return 0;
}