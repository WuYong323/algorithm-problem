#include<bits/stdc++.h>
#define N 20005
using namespace std;

int n,k;
int e[15];

struct people{
	int w,num;
}peo[N];

bool comp(people a,people b){
	if(a.w!=b.w){
		return a.w>b.w;
	}
	else{
		return a.num<b.num;
	}
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=10;++i){
		cin>>e[i];
	}
	for(int i=1;i<=n;++i){
		cin>>peo[i].w;
		peo[i].num=i;
	}
	sort(peo+1,peo+1+n,comp);
	for(int i=1;i<=n;++i){
		peo[i].w+=e[(i-1)%10+1];
	}
	sort(peo+1,peo+1+n,comp);
	for(int i=1;i<=k;++i){
		cout<<peo[i].num<<" ";
	}
	return 0;
}