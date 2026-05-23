#include<bits/stdc++.h>
using namespace std;

struct xiao{
	int h;
	int y;
};

bool comp(xiao a,xiao b){
	return a.y<b.y;
}

int main()
{
	int n,s,a,b;
	int ans=0;
	cin>>n>>s>>a>>b;
	xiao tao[5010];
	for(int i=1;i<=n;i++){
		cin>>tao[i].h>>tao[i].y;
	}
	sort(tao+1,tao+1+n,comp);
	for(int i=1;i<=n;i++){
		if(tao[i].h<=a+b){
			if(s-tao[i].y>=0){
				s-=tao[i].y;
				ans++;
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
}