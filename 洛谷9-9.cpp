#include<bits/stdc++.h>
using namespace std;

int n,m,a=2500,t;
string s;
int w[55],b[55],r[55];

int check(char z){
	t=0;
	for (int i=0;i<m;i++) {
		if(s[i]!=z){
			t++;
		}
	}
	return t;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>s;
		w[i]=w[i-1]+check('W');
		b[i]=b[i-1]+check('B');
		r[i]=r[i-1]+check('R');
	}
	for (int i=1;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			a=min(a,w[i]+b[j]-b[i]+r[n]-r[j]);
		}
	}
	cout<<a;
	return 0;
}