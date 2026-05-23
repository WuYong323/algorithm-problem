#include<bits/stdc++.h>
#define N 3005
using namespace std;

int a[N];

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=n;
		while(l<=i&&i<=r){
			int h=a[l]+a[r];
			if(h%2==0&&h/2==a[i]){
				if(i-l<=r-i-1){
					ans=max(ans,(i-l+1)*2);
				}
				else{
					ans=max(ans,(r-i)*2+1);
				}
			}
			if(h/2>=a[i]){
				r--;
			}
			else{
				l++;
			}
		}
	}
	cout<<ans<<endl;;
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