#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	map<pair<int,int>,int>g;
	for(int i=1;i<=q;i++){
		int id,x,y,num;
		cin>>id;
		if(id==1){
			cin>>x>>y>>num;
			g[{x,y}]=num;
		}
		else if(id==2){
			cin>>x>>y;
			cout<<g[{x,y}]<<endl;
		}
	}
	return 0;
}