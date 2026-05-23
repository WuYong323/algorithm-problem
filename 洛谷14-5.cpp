#include<bits/stdc++.h>
using namespace std;

struct lianbiao{
	int l;
	int r;
	int t;
}lb[100010];

void add(int i,int k,int p){
	if(p==0){
		lb[i].r=k;
		lb[i].l=lb[k].l;
		lb[k].l=i;
		lb[lb[i].l].r=i;
	}
	if(p==1){
		lb[i].l=k;
		lb[i].r=lb[k].r;
		lb[k].r=i;
		lb[lb[i].r].l=i;
	}
}

int main()
{
	int n;
	cin>>n;
	lb[0].r=0,lb[0].l=0;
	add(0,1,1);
	int k,p;
	for(int i=2;i<=n;i++){
		cin>>k>>p;
		add(i,k,p);
	}
	int m,x;
	cin>>m;
	while(m--){
		cin>>x;
		lb[x].t=1;
	}
	for(int i=lb[0].r;i!=0;i=lb[i].r){
		if(lb[i].t==0){
			cout<<i<<" ";
		}
	}
	return 0;
}