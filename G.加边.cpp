#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,m;
vector<int> e[N];
vector<int> s;

int main()
{
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;++i){
		if(e[i].size()%2){
			s.push_back(i);
		}
	}
	int t=s.size();
	if(t==1){
		cout<<1<<endl;
		cout<<s[0]<<" "<<s[0];
	}
	else if(t>1){
		if(t%2){
			cout<<t/2+1<<endl;
			for(int i=0;i<t-1;i+=2){
				cout<<s[i]<<" "<<s[i+1]<<endl;
			}
			cout<<s[t-1]<<" "<<s[t-1];
		}
		else{
			cout<<t/2<<endl;
			for(int i=0;i<t;i+=2){
				cout<<s[i]<<" "<<s[i+1]<<endl;
			}
		}	
	}
	return 0;
}