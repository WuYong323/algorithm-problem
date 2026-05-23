#include<bits/stdc++.h>
using namespace std;

int n,a,b;
int lieb[205];
bool blieb[205];
int lst[205];
queue<int> q;

int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>lst[i];
	}
	memset(lieb,-1,sizeof(lieb));
	memset(blieb,false,sizeof(blieb));
	lieb[a]=0;
	blieb[a]=true;
	q.push(a);
	while(!q.empty()){
		int a1=q.front();
		q.pop();
		int direct[2]={lst[a1],-lst[a1]};
		for(int i=0;i<2;i++){
			int aa=a1+direct[i];
			if(aa<1||blieb[aa]||aa>n){
				continue;
			}
			blieb[aa]=true;
			q.push(aa);
			lieb[aa]=lieb[a1]+1;
		}
	}
	cout<<lieb[b];
	return 0;
}