#include<bits/stdc++.h>
using namespace std;

int lst[1000005];
int n,m;

long long sum(int mid){
	long long s=0;
	for(int i=n;i>=1;i--){
		if(lst[i]>mid){
			s+=(lst[i]-mid);
		}
	}
	return s;
}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	sort(lst+1,lst+1+n);
	int l=lst[1],r=lst[n];
	long long p=0;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(sum(mid)>=m){
			p=max(p,mid);
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
	cout<<p;
	return 0;
}