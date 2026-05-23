#include<bits/stdc++.h>
using namespace std;

map<int,int> q;

int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=1;i<=n;++i){
		cin>>a;
		q[a]=i;
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>a;
		cout<<q[a]<<endl;
	}
	return 0;
}