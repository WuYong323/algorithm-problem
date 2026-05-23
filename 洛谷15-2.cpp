#include<bits/stdc++.h>
using namespace std;

struct node{
	int left;
	int right;
}tree[1000010];

int ans;

void dfs(int i,int deep){
	if(i==0){
		return;
	}
	ans=max(ans,deep);
	dfs(tree[i].left,deep+1);
	dfs(tree[i].right,deep+1);
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>tree[i].left>>tree[i].right;
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}