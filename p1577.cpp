#include<bits/stdc++.h>
#define N 10005
using namespace std;

int n,k;
double len[N];

int check(double mid){
	int res=0;
	for(int i=1;i<=n;++i){
		res+=len[i]/mid;
	}
	if(res==k) return 0;
	if(res<k) return -1;
	if(res>k) return 1;
}

int main()
{
	cin>>n>>k;
	double l=0,r=0;
	for(int i=1;i<=n;++i){
		cin>>len[i];
		r=max(r,len[i]);
	}
	while(r-l>=0.0001){
		double mid=(l+r)/2;
		if(check(mid)==1||check(mid)==0) l=mid;
		if(check(mid)==-1) r=mid;
	}
	printf("%.2f",(r+l)/2);
	return 0;
}