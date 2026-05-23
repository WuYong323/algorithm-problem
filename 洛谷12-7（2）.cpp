#include<bits/stdc++.h>
using namespace std;

int l,n,m;
vector<int> r;

bool check(int x){
	int la=0,re=0;
	for(int i=0;i<n;i++){
		if(r[i]-la<x){
			re++;
		}
		else{
			la=r[i];
		}
	}
	if(l-la<x){
		if(re<m){
			re++;
		}
		else{
			return false;
		}
	}
	return re<=m;
}

int main()
{
	cin>>l>>n>>m;
	r.resize(n);
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	int le=1,ri=l,ans=0;
	while(le<=ri){
		int mid=le+(ri-le)/2;
		if(check(mid)){
			ans=mid;
			le=mid+1;
		}
		else{
			ri=mid-1;
		}
	}
	cout<<ans;
	return 0;
}