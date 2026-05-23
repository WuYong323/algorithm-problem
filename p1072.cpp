#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int a0,a1,b0,b1;
		cin>>a0>>a1>>b0>>b1;
		int p=a0/a1;
		int q=b1/b0;
		int ans=0;
		for(int i=1;i*i<=b1;++i){
			if(b1%i==0){
				if(i%a1==0&&gcd(i/a1,p)==1&&gcd(q,b1/i)==1){
					ans++;
				}
				int j=b1/i;
				if(i==j) continue;
				if(j%a1==0&&gcd(j/a1,p)==1&&gcd(q,b1/j)==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}