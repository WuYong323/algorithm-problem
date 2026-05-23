#include<bits/stdc++.h>
using namespace std;

long long lst[10010];

long long hsh(string a){
	int t=0;
	for(int i=0;i<a.size();++i){
		t+=int(a[i]);
		t*=2;
	}
	return t;
}

int main()
{
	int n;
	cin>>n;
	string a;
	for(int i=1;i<=n;++i){
		cin>>a;
		lst[i]=hsh(a);
	}
	int ans=0;
	sort(lst+1,lst+1+n);
	for(int i=1;i<=n;++i){
		if(lst[i]!=lst[i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}