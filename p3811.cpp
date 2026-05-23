#include<bits/stdc++.h>
using namespace std;

int n,p;
int ans[3000005];

int main()
{
	cin>>n>>p;
	cout<<1<<endl;
	ans[1]=1;
	for(int i=2;i<=n;++i){
		ans[i]=p-(long long)(p/i)*ans[p%i]%p;
	}
	for(int i=2;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}