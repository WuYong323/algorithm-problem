#include<bits/stdc++.h>
using namespace std;

struct milk{
	int p;
	int a;
}ml[5010];

bool comp(milk a,milk b){
	return a.p<b.p;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>ml[i].p>>ml[i].a;
	}
	sort(ml+1,ml+1+m,comp);
	long long sum=0;
	int l;
	for(l=1;l<=m;l++){
		sum+=ml[l].a*ml[l].p;
		n-=ml[l].a;
		if(n-ml[l+1].a<0){
			break;
		}
	}
	sum+=n*ml[l+1].p;
	cout<<sum;
	return 0;
}