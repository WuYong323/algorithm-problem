#include<bits/stdc++.h>
using namespace std;

int lst[100005];
int n,m;

bool tel(int a){
	int sum=0,g=0;
	for(int i=1;i<=n;i++){
		sum+=lst[i];
		if(lst[i]>a){
			return false;
		}
		if(sum>a){
			sum=lst[i];
			g++;
		}
	}
	return g+1<=m;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	int l=1,r=1e9;
	int p=1e9;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(tel(mid)){
			p=(p,mid);
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<p;
	return 0;
}