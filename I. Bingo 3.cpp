#include<bits/stdc++.h>
using namespace std;

int a[55][55];

void solve(){
	int n,k;
	cin>>n>>k;
	if(k<n||n*n-k<n-1){
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
	memset(a,0,sizeof(a));
	a[1][1]=k;
	int len=n*n;
	for(int i=2,j=2;i<=n;){
		a[i][j]=len;
		len--;
		++i;
		++j;
	}
	len=1;
	for(int i=2;i<=n;++i){
		a[1][i]=len;
		len++;
	}
	len=n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(len==k){
				len++;
			}
			if(!a[i][j]){
				a[i][j]=len;
				++len;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}